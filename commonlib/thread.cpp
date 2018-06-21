#include "thread.h"
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <sys/prctl.h>

CThread::CThread(const std::string& strName)
{
	status_  = IDLE;
	strName_ = strName;
	pthread_cond_init(&condt_, NULL);
	pthread_create(&pt_, NULL, Run, this);

}

CThread::~CThread()
{
	lock_.Lock();
	while(!taskList_.empty())
	{
		/* Remove task */
		CFunctor* pFunctor = taskList_.front();	
		taskList_.pop_front();

		delete pFunctor;
	}
		
	status_ = EXIT;
	pthread_cond_signal(&condt_);
	lock_.UnLock();
    pthread_join(pt_, NULL);
	pthread_cond_destroy(&condt_);	

}

void* CThread::Run(void* para)
{
	CThread* pThread = (CThread*)para;

	/* Set thread name, linux kerner > 2.6.9 supoort*/
	if(!pThread->strName_.empty())
	{
		prctl(PR_SET_NAME, pThread->strName_.c_str());			
	}

	CFunctor* pFunctor = NULL;
	//std::list<CFunctor*>::const_iterator it;

	//int id = (int)pThread->pt_;
	while(pThread->status_ != EXIT)
	{
		pThread->lock_.Lock();
		if(pThread->taskList_.size() == 0)
		{
			pthread_cond_wait(&pThread->condt_, &pThread->lock_.GetLock());
		}

		pFunctor = pThread->taskList_.front();	
		while(!pThread->taskList_.empty())
		{
			/* Excute task */
			pThread->taskList_.pop_front();
			pThread->lock_.UnLock();
			
			(*pFunctor)();
		
			delete pFunctor;

			pThread->lock_.Lock();
			pFunctor = pThread->taskList_.front();	
		}
		
		pThread->lock_.UnLock();
	}

	pthread_testcancel();
	return NULL;
}

void CThread::EnqueueTask(CFunctor* pFunctor)
{
	CAutoLock lock(lock_.GetLock());
	taskList_.push_back(pFunctor);	

	/* Signal wait*/
	pthread_cond_signal(&condt_);
}


void CThread::EnqueueTaskFront(CFunctor* pFunctor)
{
	CAutoLock lock(lock_.GetLock());
	taskList_.push_front(pFunctor);	
	
	/* Signal wait*/
	pthread_cond_signal(&condt_);
}

