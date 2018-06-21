/*------------------------------------------------------
 *
 * class       : None
 * description : Bind functor template
 * date        : 2011-7-21
 * author      : wanghonggang
 *
 *----------------------------------------------------*/

#ifndef _BIND_H_
#define _BIND_H_

#include "functor.h"

template<class FunRetT>
inline CFunctor* Bind(FunRetT(*funPtr)())
{
	return new CFunctor0<FunRetT(*)()>(funPtr);
}

template<class FunRetT, class FunPara1T, class Para1T>
inline CFunctor* Bind(FunRetT(*funPtr)(FunPara1T), Para1T p1)
{
	return new CFunctor1<FunRetT(*)(FunPara1T), Para1T>(funPtr, p1);
}

template<class FunRetT, class FunPara1T, class FunPara2T, class Para1T, class Para2T>
inline CFunctor* Bind(FunRetT(*funPtr)(FunPara1T, FunPara2T), Para1T p1, Para2T p2)
{
	return new CFunctor2<FunRetT(*)(FunPara1T, FunPara2T), Para1T, Para2T>(funPtr, p1, p2);
}

template<class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class Para1T, class Para2T, class Para3T>
inline CFunctor* Bind(FunRetT(*funPtr)(FunPara1T, FunPara2T, FunPara3T), Para1T p1, Para2T p2, Para3T p3)
{
	return new CFunctor3<FunRetT(*)(FunPara1T, FunPara2T, FunPara3T), Para1T, Para2T, Para3T>(funPtr, p1, p2, p3);
}

template<class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class FunPara4T, class Para1T, class Para2T, class Para3T, class Para4T>
inline CFunctor* Bind(FunRetT(*funPtr)(FunPara1T, FunPara2T, FunPara3T, FunPara4T), Para1T p1, Para2T p2, Para3T p3, Para4T p4)
{
	return new CFunctor4<FunRetT(*)(FunPara1T, FunPara2T, FunPara3T, FunPara4T), Para1T, Para2T, Para3T, Para4T>(funPtr, p1, p2, p3, p4);
}

template<class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class FunPara4T, class FunPara5T, class Para1T, class Para2T, class Para3T, class Para4T, class Para5T>
inline CFunctor* Bind(FunRetT(*funPtr)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T), Para1T p1, Para2T p2, Para3T p3, Para4T p4, Para5T p5)
{
	return new CFunctor5<FunRetT(*)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T), Para1T, Para2T, Para3T, Para4T, Para5T>(funPtr, p1, p2, p3, p4, p5);
}

/*-------------------------------class object----------------------------------*/

template<class ObjPtrT, class ObjT, class FunRetT>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)())
{
	return new CObjFunctor0<ObjPtrT, FunRetT(ObjT::*)()>(objPtr, funPtr);	
}

template<class ObjPtrT, class ObjT, class FunRetT, class FunPara1T, class Para1T>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)(FunPara1T), Para1T p1)
{
	return new CObjFunctor1<ObjPtrT, FunRetT(ObjT::*)(FunPara1T), Para1T>(objPtr, funPtr, p1);
}

template<class ObjPtrT, class ObjT, class FunRetT, class FunPara1T, class FunPara2T, class Para1T, class Para2T>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)(FunPara1T, FunPara2T), Para1T p1, Para2T p2)
{
	return new CObjFunctor2<ObjPtrT, FunRetT(ObjT::*)(FunPara1T, FunPara2T), Para1T, Para2T>(objPtr, funPtr, p1, p2);
}

template<class ObjPtrT, class ObjT, class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class Para1T, class Para2T, class Para3T>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)(FunPara1T, FunPara2T, FunPara3T), Para1T p1, Para2T p2, Para3T p3)
{
	return new CObjFunctor3<ObjPtrT, FunRetT(ObjT::*)(FunPara1T, FunPara2T, FunPara3T), Para1T, Para2T, Para3T>(objPtr, funPtr, p1, p2, p3);
}

template<class ObjPtrT, class ObjT, class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class FunPara4T, class Para1T, class Para2T, class Para3T, class Para4T>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)(FunPara1T, FunPara2T, FunPara3T, FunPara4T), Para1T p1, Para2T p2, Para3T p3, Para4T p4)
{
	return new CObjFunctor4<ObjPtrT, FunRetT(ObjT::*)(FunPara1T, FunPara2T, FunPara3T, FunPara4T), Para1T, Para2T, Para3T, Para4T>(objPtr, funPtr, p1, p2, p3, p4);
}

template<class ObjPtrT, class ObjT, class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class FunPara4T, class FunPara5T, class Para1T, class Para2T, class Para3T, class Para4T, class Para5T>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T), Para1T p1, Para2T p2, Para3T p3, Para4T p4, Para5T p5)
{
	return new CObjFunctor5<ObjPtrT, FunRetT(ObjT::*)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T), Para1T, Para2T, Para3T, Para4T, Para5T>(objPtr, funPtr, p1, p2, p3, p4, p5);
}

template<class ObjPtrT, class ObjT, class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class FunPara4T, class FunPara5T, class FunPara6T, class Para1T, class Para2T, class Para3T, class Para4T, class Para5T, class Para6T>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T, FunPara6T), Para1T p1, Para2T p2, Para3T p3, Para4T p4, Para5T p5, Para6T p6)
{
	return new CObjFunctor6<ObjPtrT, FunRetT(ObjT::*)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T, FunPara6T), Para1T, Para2T, Para3T, Para4T, Para5T, Para6T>(objPtr, funPtr, p1, p2, p3, p4, p5, p6);
}

template<class ObjPtrT, class ObjT, class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class FunPara4T, class FunPara5T, class FunPara6T, class FunPara7T, class Para1T, class Para2T, class Para3T, class Para4T, class Para5T, class Para6T, class Para7T>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T, FunPara6T,FunPara7T), Para1T p1, Para2T p2, Para3T p3, Para4T p4, Para5T p5, Para6T p6, Para7T p7)
{
	return new CObjFunctor7<ObjPtrT, FunRetT(ObjT::*)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T, FunPara6T, FunPara7T), Para1T, Para2T, Para3T, Para4T, Para5T, Para6T , Para7T>(objPtr, funPtr, p1, p2, p3, p4, p5, p6, p7);
}

template<class ObjPtrT, class ObjT, class FunRetT, class FunPara1T, class FunPara2T, class FunPara3T, class FunPara4T, class FunPara5T, class FunPara6T, class FunPara7T, class FunPara8T, class Para1T, class Para2T, class Para3T, class Para4T, class Para5T, class Para6T, class Para7T, class Para8T>
inline CFunctor* Bind(ObjPtrT objPtr, FunRetT(ObjT::*funPtr)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T, FunPara6T,FunPara7T, FunPara8T), Para1T p1, Para2T p2, Para3T p3, Para4T p4, Para5T p5, Para6T p6, Para7T p7, Para8T p8)
{
	return new CObjFunctor8<ObjPtrT, FunRetT(ObjT::*)(FunPara1T, FunPara2T, FunPara3T, FunPara4T, FunPara5T, FunPara6T, FunPara7T, FunPara8T), Para1T, Para2T, Para3T, Para4T, Para5T, Para6T, Para7T, Para8T>(objPtr, funPtr, p1, p2, p3, p4, p5, p6, p7, p8);
}


#endif /* _BIND_H_ */

