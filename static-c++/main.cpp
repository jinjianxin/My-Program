#include <iostream>
using namespace std;

class A
{
	public:
		A();
		~A();
	static int i;
	static void f(bool);
	void test();
	private:
	static int j;
	char *name;
};


A::A()
{
	name = "jjx";
}

A::~A()
{
}

void A::f(bool a)
{
	//cout<<name<<endl;  error;

	if(a)
	{
		cout<<"i="<<i<<endl;
	}
	else
	{
		cout<<"j="<<j<<endl;
	}
}

void A::test()
{
}

int A::i = 0;
int A::j = 1;

int main()
{
	A *a = new A;
	A::f(true);	
	a->test();

	return 0;	
}
