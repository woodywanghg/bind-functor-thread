#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <vector>
#include <string>

class CThread;
class CFunctor;

class CThreadPool
{
public:
	CThreadPool(int num, const std::string& strName = "");
	~CThreadPool();

public:
	void EnqueueTask(CFunctor* pFunctor);
	void EnqueueTaskIndex(CFunctor* pFunctor, int index);
	void EnqueueTaskFront(CFunctor* pFunctor);
	void EnqueueTaskFront(CFunctor* pFunctor, int index);

private:
	int num_;
	unsigned int schedules_;
	std::vector<CThread*> threadVec_;	
};

#endif /* _THREAD_POOL_H_ */
