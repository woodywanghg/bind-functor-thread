#include <iostream>
#include <stdio.h>
#include "threadpool.h"
#include "thread.h"
#include "functor.h"


CThreadPool::CThreadPool(int num, const std::string& strName)
{
	num_       = num;
	schedules_ = 0;
	char buff[6] = {0};
	CThread* pThread = NULL;
	for(int i  = 0; i < num_; i++)
	{
		if(!strName.empty())
		{
			snprintf(buff, sizeof(buff), "%d", i+1);
			std::string strThreadName = strName + "-" + buff;
			pThread = new CThread(strThreadName);
		}
		else
		{
			pThread = new CThread();
		}

		threadVec_.push_back(pThread);
	}
}
	
CThreadPool::~CThreadPool()
{
	std::vector<CThread*>::iterator it = threadVec_.begin();
	while(it != threadVec_.end())
	{
		CThread* pThread = *it;
		delete pThread;
		it++;
	}
}

void CThreadPool::EnqueueTask(CFunctor* pFunctor)
{
	threadVec_[schedules_ % num_]->EnqueueTask(pFunctor);
	schedules_++;
}

void CThreadPool::EnqueueTaskIndex(CFunctor* pFunctor, int index)
{
	threadVec_[index]->EnqueueTask(pFunctor);
}

void CThreadPool::EnqueueTaskFront(CFunctor* pFunctor)
{
	threadVec_[schedules_ % num_]->EnqueueTaskFront(pFunctor);
	schedules_++;
}

void CThreadPool::EnqueueTaskFront(CFunctor* pFunctor, int index)
{
	threadVec_[index]->EnqueueTaskFront(pFunctor);
}

