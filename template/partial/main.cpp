#include <iostream>
#include <string.h>

//using namespace std;

/**
 *显示特化
 */
template <class T>
const T& min(const T& a,const T& b)
{
	return (a<b)?a:b;
}

template<>
const char* const& min<const char*>(const char* const&a,const char* const&b)
{
	return (strcmp(a,b)<0)?a:b;
}

/**
 *半特化
 */
template <class T,class U>
class C
{
	public:
		void f()
		{
			std::cout<<"Primary Template"<<std::endl;
		}
};

template <class U>
class C<int ,U>
{
	public:
		void f()
		{
			std::cout<<"T == int"<<std::endl;
		}
};

template <class T>
class C<T,double>
{
	public:
		void f()
		{
			std::cout<<"T == double"<<std::endl;
		}
};

template <class T,class U>
class C<T*,U>
{
	public:
		void f()
		{
			std::cout<<"T* and U"<<std::endl;
		}
	
};

template <class T,class U>
class C<T,U*>
{
	public:
		void f()
		{
			std::cout<<"T and U*"<<std::endl;
		}
	
};

template <class T,class U>
class C<T*,U*>
{
	public:
		void f()
		{
			std::cout<<"T* and U*"<<std::endl;
		}
};

template <class T>
class C<T,T>
{
	public:
		void f()
		{
			std::cout<<"T=U"<<std::endl;
		}
};


int main(int argc,char *argv[])
{
	const char *s2 ="say",*s1 = "test";
	std::cout<< min(s1,s2) <<std::endl;
	std::cout<< min<>(s1,s2) <<std::endl;

	C<float,int>().f();
	C<int,float>().f();
	C<float,double>().f();
	C<float,float>().f();
	C<float*,float>().f();
	C<float,float*>().f();
	C<float*,int*>().f();

	/**
	 *
	 *以下的函数调用错误
	 */

	//C<int,int>().f();
	//C<float,float>().f();
	//C<double,double>().f();
	//C<float*,float*>().f();
	//C<int*,float>().f();
	//C<int*,int*>().f();

}
