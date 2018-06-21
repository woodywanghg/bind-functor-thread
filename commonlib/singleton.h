#ifndef _SINGLETON_H_
#define _SINGLETON_H_

template<class T>
class CSingleton : private T
{
public:
	static T& Instance()
	{
		static CSingleton<T> singleton;
		return singleton;
	}

private:
	CSingleton(){};
	~CSingleton(){};
	CSingleton(const T&);
	CSingleton& operator=(const T&);
};

#endif /* _SINGLETON_H_ */
