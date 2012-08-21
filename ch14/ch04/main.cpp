#include <iostream>

using namespace std;

//没有虚析构函数，继承类没有析构

class Thing
{
	public:
		Thing() {cout<<"Thing init"<<endl;}
		virtual void test() {cout<<"Ting test"<<endl;}
		~Thing() {cout<<"Thing destroy"<<endl;}
};

class Animal : public Thing
{
	public:
		Animal() {cout<<"Animal init"<<endl;};
		virtual void test() {cout<<"Animal test"<<endl;}
		~Animal() {cout<<"Animal destroy"<<endl;}
};

class A
{
	public:
		A() { cout<<"A init"<<endl;}
		~A() {cout<<"A destroy"<<endl;};
};

class B : public A
{
	public:
		B() {cout<<"B init"<<endl;}
		~B() {cout<<"B destroy"<<endl;};
};


int main()
{
	Thing *a = new Thing();
	Animal *b = new Animal();


	Thing* array[2];

	array[0] = a;
	array[1] = b;

	for(int i=0;i<2;i++)
	{
		array[i]->test();
		delete array[i];
	}

	return 0;
}
