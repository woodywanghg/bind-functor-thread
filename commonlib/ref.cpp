#include "ref.h"
#include <iostream>

CRef::CRef()
{
	ref_ = 0;
}

CRef::~CRef()
{

}

int CRef::AddRef()
{
	return __sync_add_and_fetch(&ref_, 1);
}

int CRef::Release()
{
	return __sync_sub_and_fetch(&ref_, 1);
}
	
int CRef::Release(int ref)
{
	return __sync_sub_and_fetch(&ref_, ref);
}
	
int CRef::GetRef()
{
	return __sync_fetch_and_add(&ref_, 0); 
} 
