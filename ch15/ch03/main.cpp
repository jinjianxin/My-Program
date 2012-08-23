/*
 *析构函数中的虚机制
 */

#include <iostream>

using namespace std;

class A
{
	public:
		virtual ~A() 
		{ 
			f();
			cout<<"destroy"<<"A"<<endl;
		}
		virtual void f() {cout<<"A callback"<<"f()"<<endl;};
};

class B : public A
{
	public:
		virtual ~B() 
		{
			cout<<"destroy"<<"B"<<endl;
		}
		virtual void f() 
		{
			cout<<"B callback"<<"f()"<<endl;
		}
};

int main()
{
	B *b = new B;
	delete b; //此处调用时调用A B的析构函数 ，f只在A的析构函数中调用，不会调用B的f函数，此时析构函数只调用成员函数的本地版本
}
