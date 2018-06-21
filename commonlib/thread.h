/*------------------------------------------------------
 *
 * class       : CThread 
 * description : Thread wrapper
 * date        : 2011-7-22
 * author      : wanghonggang
 *
 *----------------------------------------------------*/

#ifndef _THREAD_H_
#define _THREAD_H_

#include "lock.h"
#include <list>
#include <string>
#include <pthread.h>
#include "functor.h"

class CThread
{
public:
	enum ThreadStatus
	{
		IDLE,
		RUN,
		SUSPEND,
		BUSY,
		EXIT
	};

public:
	CThread(const std::string& strName = "");
	~CThread();

	void EnqueueTask(CFunctor* pFunctor);
	void EnqueueTaskFront(CFunctor* pFunctor);

private:
	static void* Run(void* para);	

private:
	CLock lock_;
	pthread_t pt_;
	ThreadStatus status_;			
	pthread_cond_t condt_;
	std::string strName_;
	std::list<CFunctor*> taskList_;	
};

#endif /* _THREAD_H_ */
