/*------------------------------------------------------
 *
 * class       : CLock & CAutoLock
 * description : mutex lock wrapper
 * date        : 2011-7-12
 * author      : wanghonggang
 *
 *----------------------------------------------------*/

#ifndef _LOCK_H_
#define _LOCK_H_

#include <pthread.h>

/* class CLock */
class CLock
{
public:
	CLock();
	~CLock();

public:
	void Lock()   { pthread_mutex_lock(&lock_);   } 
	void UnLock() { pthread_mutex_unlock(&lock_); } 
	pthread_mutex_t& GetLock() { return lock_; }		

private:
	pthread_mutex_t lock_;
	pthread_mutexattr_t attr_;

	friend class CAutoLock;
};

/* class CAutoLock */
class CAutoLock
{
public:
	explicit CAutoLock(CLock& lock);
	explicit CAutoLock(pthread_mutex_t& lock);
	~CAutoLock();
private:
	pthread_mutex_t& lock_;
};

class CRWLock
{
public:
	CRWLock();
	~CRWLock();

	
	void RLock();
	void WLock();
	void RUnlock();
	void WUnlock();

private:
	int read_;
	int write_;
};

class CAutoRLock
{
public:
	explicit CAutoRLock(CRWLock& lock);
	~CAutoRLock();
private:
	CRWLock& lock_;
};

class CAutoWLock
{
public:
	explicit CAutoWLock(CRWLock& lock);
	~CAutoWLock();
private:
	CRWLock& lock_;
};



#endif /* _LOCK_H_ */
