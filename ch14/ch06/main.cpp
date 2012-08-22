#include <iostream>

using namespace std;

class A
{
	int a;
	public:
	A(int i) :a(i) {};
	virtual void print() {cout<<"A::print a="<<a<<endl ;}
	int get_a() {return a;}
};

class B
{
	int b;
	public:
	B(int i):b(i) {};
	void print() {cout<<"B::print b="<<b<<endl;}
	int get_b() {return b;}
};

class C : public A,public B
{
	int c;
	public:
	C(int i,int j,int k):A(i),B(j),c(k) {}
	void print() {A::print();B::print();}
	void get_ab() {cout<<"get a="<<A::get_a()<<"\t"<<"get b="<<B::get_b()<<endl;}

};

class D : public C
{
	public:
	D(int i,int j,int k):C(i,j,k) {};
	void print() {cout<<"==================\n"<<endl;}
};

int main()
{
	D d(1,2,3);

	d.print(); //printf "=====================";

	C c = d;
	A *a = &c;
	B *b = &c;

	A *a1 = &d;
	a1->print(); //调用d->print();

	a->print();  //调用c->print(); print为虚函数
	b->print();  //调用b->print();


	a->get_a();
	b->get_b();
	c.get_ab();

//	c.print();

	return 0;
}
