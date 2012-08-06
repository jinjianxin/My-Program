#include <iostream>

using namespace std;

class A;
class B;
class C;

class A
{
	public:
		A(char *str);
		A();
		~A();
	static A *a;
	virtual void callback() = 0;
	virtual void test() = 0;
	char *name;
};


A *A::a = 0;

class B : public A
{
	public:
		B(char *str);
		B();
		~B();
	static B *b;
	void callback();
	void test();
	char *name;
	void set_name(char *str);
	char *get_name(){return name;};
};

B *B::b = 0;

class C : public B
{
	public:
		C();
		~C();
	static C *c;
	void test(char *str);
};

C *C::c = 0;

A::A(char *str)
{
}

A::A()
{
}

A::~A()
{
}


B::B(char *str)  
{
}

B::B()
{
}

B::~B()
{
}

void B::callback()
{
	cout<<"callbacl\t"<<name<<endl;
}

void B::test()
{
}

void B::set_name(char *str)
{
	name = str;
}

C::C()
{
}

C::~C()
{
}

void C::test(char *str)
{
}



int main()
{
	C *c = new C();
	c->set_name("jjx");
	c->callback();
	cout<<c->get_name()<<endl;

	A::a->callback();

	cout<<"***********************************"<<endl;

	return 0;
}
