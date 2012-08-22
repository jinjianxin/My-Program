#include <iostream>

using namespace std;

class A
{
	int a;
	public:
	void x() const {}
	int i() { return 1;}
};

class B 
{
	int a;
	public:
	virtual void x() const {}
	int i() {return 1 ;}
};

class C
{
	int a;
	public:
		virtual void x() const {}
		virtual int i() {return 1;}
};

class D
{
	public:
	void x() const {}
	int i() { return 1;}
};

int main()
{
	cout<<"sizeof(D)="<<sizeof(D)<<endl; //1
	cout<<"sizeof(A)="<<sizeof(A)<<endl; // 4 int占4位 
	cout<<"sizeof(B)="<<sizeof(B)<<endl; // 8 int+虚函数表 =8
	cout<<"sizeof(C)="<<sizeof(C)<<endl; // 同B
}
