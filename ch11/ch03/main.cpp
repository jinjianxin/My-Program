#include <stdio.h>
#include <iostream>

using namespace std;

class A
{
	public:
	int i;
	int j;

	void fun();
	int callback(const int m);
};

void A::fun()
{
	 cout<<"fun is callback"<<endl;
}

int A::callback(const int m)
{
	int i = 10;
	return i;
}

int A::*pi = & A::i ;

void (A::*pmf)() = &A::fun;
int (A::*call)(int m) = &A::callback;

int main()
{
	A a,b;
	a.i = 0;
	b.i = 3;
	
	int m = a.callback(1);
	cout<<"callback\t"<<m<<endl;
	
	cout<<a.*pi<<endl;
	cout<<b.*pi<<endl;

	a.*pi = 10;
	cout<<a.i<<endl;

	(a.*pmf)();
	
	int j = (a.*call)(10);
	cout<<j<<endl;

	return 0;
}
