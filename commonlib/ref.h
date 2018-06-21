#ifndef _REF_H_
#define _REF_H_

class CRef
{
public:
	CRef();
	virtual ~CRef();

public:
	virtual int AddRef();	
	virtual int Release();	
	virtual int Release(int ref);	
	virtual int GetRef();

private:
	int ref_;		
};

#endif /* _REF_H_ */
