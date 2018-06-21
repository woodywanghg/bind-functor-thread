#include "lock.h"
/*
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
 
#define gettid() syscall(__NR_gettid)
*/


CLock::CLock()
{

	pthread_mutexattr_init(&attr_);
	pthread_mutexattr_settype(&attr_, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&lock_, &attr_);
}

CLock::~CLock()
{
	pthread_mutex_destroy(&lock_);
	pthread_mutexattr_destroy(&attr_);
}

CAutoLock::CAutoLock(CLock& lock) : lock_(lock.lock_)
{
	pthread_mutex_lock(&lock_);
}
CAutoLock::CAutoLock(pthread_mutex_t& lock) : lock_(lock)
{
	pthread_mutex_lock(&lock_);
}

CAutoLock::~CAutoLock()
{
	pthread_mutex_unlock(&lock_);
}

CRWLock::CRWLock()
{
	write_ = 0;
	read_  = 0;
}

CRWLock::~CRWLock()
{

}

void CRWLock::RLock()
{
	for (;;) 
	{
		while(write_)
		{
			__sync_synchronize();
		}

		__sync_add_and_fetch(&read_,1);
		if (write_) 
		{
			__sync_sub_and_fetch(&read_,1);
		}
		else
		{
			break;
		}
	}
}

void CRWLock::WLock()
{
	while (__sync_lock_test_and_set(&write_, 1)) {}
	while(read_) 
	{
		__sync_synchronize();
	}
}

void CRWLock::RUnlock()
{	
	__sync_sub_and_fetch(&read_, 1);
}

void CRWLock::WUnlock()
{	
	__sync_lock_release(&write_);
}


CAutoRLock::CAutoRLock(CRWLock& lock) : lock_(lock)
{
	lock_.RLock();
}

CAutoRLock::~CAutoRLock()
{
	lock_.RUnlock();
}

CAutoWLock::CAutoWLock(CRWLock& lock) : lock_(lock)
{
	lock_.WLock();
}

CAutoWLock::~CAutoWLock()
{
	lock_.WUnlock();
}
