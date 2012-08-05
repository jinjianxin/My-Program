#include <iostream>

using namespace std;

class A
{
	public:
		A();
		~A();
		void set_i(int& i);
		void test() const;
		void test1() const;
		int number;
};

A::A()
{
	number =0;
}

A::~A()
{
}

void A::test() const
{
	test1();
}

void A::test1() const
{
//	set_i(number++);
}

void A::set_i(int& i)
{
	number = i;
	cout<<"number"<<number<<endl;
	test();
}

int main()
{
	A *a = new A();
	
	int i = 3;
	int& c=i;
	a->set_i(c);

	a->test();

	return 0;
}

