#ifndef _WAIT_H_
#define _WAIT_H_

#include "lock.h"

class CWait
{
public:
	CWait();
	~CWait();

public:
	void Wait();	
	void Signal();

private:
	CLock lock_;	
	pthread_cond_t cond_;
};

#endif /* _WAIT_H_ */
