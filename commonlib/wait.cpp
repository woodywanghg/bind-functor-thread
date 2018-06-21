#include "wait.h"

CWait::CWait()
{
	pthread_cond_init(&cond_, NULL);
}

CWait::~CWait()
{
	pthread_cond_destroy(&cond_);
}

void CWait::Wait()
{
	lock_.Lock();
	pthread_cond_wait(&cond_, &lock_.GetLock());
	lock_.UnLock();
}

void CWait::Signal()
{
	lock_.Lock();
	pthread_cond_signal(&cond_);
	lock_.UnLock();
}
