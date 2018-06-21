/*------------------------------------------------------
 *
 * class       : CFunctorX
 * description : functor
 * date        : 2011-7-21
 * author      : wanghonggang
 *
 *----------------------------------------------------*/

#ifndef _FUNCTOR_H_
#define _FUNCTOR_H_

class CFunctor
{
public:
	CFunctor(){}
	virtual ~CFunctor(){}

public:
	virtual void operator()(){}
};

template<class FunPtrT>
class CFunctor0 : public CFunctor
{
public:
	CFunctor0(FunPtrT funPtr) : funPtr_(funPtr){}
	~CFunctor0(){}

	void operator()()
	{
		funPtr_();
	}

private:
	FunPtrT funPtr_;
};

template<class FunPtrT, class Param1T>
class CFunctor1 : public CFunctor
{
public:
	CFunctor1(FunPtrT funPtr, Param1T p1) : funPtr_(funPtr), p1_(p1){}
	~CFunctor1(){}

	void operator()()
	{
		funPtr_(p1_);
	}

private:
	FunPtrT funPtr_;
	Param1T  p1_;
};

template<class FunPtrT, class Param1T, class Param2T>
class CFunctor2 : public CFunctor
{
public:
	CFunctor2(FunPtrT funPtr, Param1T p1, Param2T p2) : funPtr_(funPtr), p1_(p1), p2_(p2){}
	~CFunctor2(){}

	void operator()()
	{
		funPtr_(p1_, p2_);
	}

private:
	FunPtrT funPtr_;
	Param1T  p1_;
	Param2T  p2_;
};


template<class FunPtrT, class Param1T, class Param2T, class Param3T>
class CFunctor3 : public CFunctor
{
public:
	CFunctor3(FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3) : funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3){}
	~CFunctor3(){}

	void operator()()
	{
		funPtr_(p1_, p2_, p3_);
	}

private:
	FunPtrT funPtr_;
	Param1T  p1_;
	Param2T  p2_;
	Param3T  p3_;
};



template<class FunPtrT, class Param1T, class Param2T, class Param3T, class Param4T>
class CFunctor4 : public CFunctor
{
public:
	CFunctor4(FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3, Param4T p4) : funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3), p4_(p4){}
	~CFunctor4(){}

	void operator()()
	{
		funPtr_(p1_, p2_, p3_, p4_);
	}

private:
	FunPtrT funPtr_;
	Param1T  p1_;
	Param2T  p2_;
	Param3T  p3_;
	Param4T  p4_;
};

template<class FunPtrT, class Param1T, class Param2T, class Param3T, class Param4T, class Param5T>
class CFunctor5 : public CFunctor
{
public:
	CFunctor5(FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3, Param4T p4, Param5T p5) : funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5){}
	~CFunctor5(){}

	void operator()()
	{
		funPtr_(p1_, p2_, p3_, p4_, p5_);
	}

private:
	FunPtrT funPtr_;
	Param1T  p1_;
	Param2T  p2_;
	Param3T  p3_;
	Param4T  p4_;
	Param5T  p5_;
};

/*-------------------------------class object----------------------------------*/

template<class ObjPtrT, class FunPtrT>
class CObjFunctor0 : public CFunctor
{
public:
	CObjFunctor0(ObjPtrT objPtr, FunPtrT funPtr) : objPtr_(objPtr), funPtr_(funPtr){}
	~CObjFunctor0(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)();
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;

};

template<class ObjPtrT, class FunPtrT, class Param1T>
class CObjFunctor1 : public CFunctor
{
public:
	CObjFunctor1(ObjPtrT objPtr, FunPtrT funPtr, Param1T p1) : objPtr_(objPtr), funPtr_(funPtr), p1_(p1){}
	~CObjFunctor1(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)(p1_);
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;
	Param1T p1_;
};

template<class ObjPtrT, class FunPtrT, class Param1T, class Param2T>
class CObjFunctor2 : public CFunctor
{
public:
	CObjFunctor2(ObjPtrT objPtr, FunPtrT funPtr, Param1T p1, Param2T p2) : objPtr_(objPtr), funPtr_(funPtr), p1_(p1), p2_(p2){}
	~CObjFunctor2(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)(p1_, p2_);
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;
	Param1T p1_;
	Param2T p2_;
};

template<class ObjPtrT, class FunPtrT, class Param1T, class Param2T, class Param3T>
class CObjFunctor3 : public CFunctor
{
public:
	CObjFunctor3(ObjPtrT objPtr, FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3) : objPtr_(objPtr), funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3){}
	~CObjFunctor3(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)(p1_, p2_, p3_);
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;
	Param1T p1_;
	Param2T p2_;
	Param3T p3_;
};

template<class ObjPtrT, class FunPtrT, class Param1T, class Param2T, class Param3T, class Param4T>
class CObjFunctor4 : public CFunctor
{
public:
	CObjFunctor4(ObjPtrT objPtr, FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3, Param4T p4) : objPtr_(objPtr), funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3), p4_(p4){}
	~CObjFunctor4(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)(p1_, p2_, p3_, p4_);
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;
	Param1T p1_;
	Param2T p2_;
	Param3T p3_;
	Param4T p4_;
};

template<class ObjPtrT, class FunPtrT, class Param1T, class Param2T, class Param3T, class Param4T, class Param5T>
class CObjFunctor5 : public CFunctor
{
public:
	CObjFunctor5(ObjPtrT objPtr, FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3, Param4T p4, Param5T p5) : objPtr_(objPtr), funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5){}
	~CObjFunctor5(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)(p1_, p2_, p3_, p4_, p5_);
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;
	Param1T p1_;
	Param2T p2_;
	Param3T p3_;
	Param4T p4_;
	Param5T p5_;
};

template<class ObjPtrT, class FunPtrT, class Param1T, class Param2T, class Param3T, class Param4T, class Param5T, class Param6T>
class CObjFunctor6 : public CFunctor
{
public:
	CObjFunctor6(ObjPtrT objPtr, FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3, Param4T p4, Param5T p5, Param6T p6) : objPtr_(objPtr), funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5), p6_(p6){}
	~CObjFunctor6(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)(p1_, p2_, p3_, p4_, p5_, p6_);
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;
	Param1T p1_;
	Param2T p2_;
	Param3T p3_;
	Param4T p4_;
	Param5T p5_;
	Param6T p6_;
};

template<class ObjPtrT, class FunPtrT, class Param1T, class Param2T, class Param3T, class Param4T, class Param5T, class Param6T, class Param7T>
class CObjFunctor7 : public CFunctor
{
public:
	CObjFunctor7(ObjPtrT objPtr, FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3, Param4T p4, Param5T p5, Param6T p6, Param7T p7) : objPtr_(objPtr), funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5), p6_(p6), p7_(p7){}
	~CObjFunctor7(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)(p1_, p2_, p3_, p4_, p5_, p6_,p7_);
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;
	Param1T p1_;
	Param2T p2_;
	Param3T p3_;
	Param4T p4_;
	Param5T p5_;
	Param6T p6_;
	Param7T p7_;
};

template<class ObjPtrT, class FunPtrT, class Param1T, class Param2T, class Param3T, class Param4T, class Param5T, class Param6T, class Param7T, class Param8T>
class CObjFunctor8: public CFunctor
{
public:
	CObjFunctor8(ObjPtrT objPtr, FunPtrT funPtr, Param1T p1, Param2T p2, Param3T p3, Param4T p4, Param5T p5, Param6T p6, Param7T p7,Param8T p8) : objPtr_(objPtr), funPtr_(funPtr), p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5), p6_(p6), p7_(p7), p8_(p8){}
	~CObjFunctor8(){}

public:
	void operator()()
	{
		(objPtr_->*funPtr_)(p1_, p2_, p3_, p4_, p5_, p6_,p7_, p8_);
	}

private:
	ObjPtrT objPtr_;
	FunPtrT funPtr_;
	Param1T p1_;
	Param2T p2_;
	Param3T p3_;
	Param4T p4_;
	Param5T p5_;
	Param6T p6_;
	Param7T p7_;
	Param8T p8_;
};
#endif /* _FUNCTOR_H_ */
