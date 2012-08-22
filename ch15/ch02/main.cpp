#include <iostream>

using namespace std;

class A
{
	int a;
	public:
	virtual string name() {return "A::jjx";}
	virtual string decs() {return "B::xjj";}
};

class B :public A
{
	int a;
	public:
	virtual string name() {return "B::jjx";}
	virtual string decs() {return "b::xjj";}
};

void callback1(A a)
{
	cout<<"a.name"<<endl;
	cout<<a.name()<<endl;  //两次都调用A::name()  对象切片  虚函数不允许通过传递地址的方式调用
}

void callback2(A& a)
{
	cout<<"a.name"<<endl;
	cout<<a.name()<<endl; //调用正常 可以通过传递引用或者指针实现运行时多态
}

int main()
{
	A a;
	B b;
	callback1(a);
	callback1(b);

	cout<<"*************************************"<<endl;

	callback2(a);
	callback2(b);
}
