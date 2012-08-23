#include <iostream>

using namespace std;

class A
{
	public:
		A(int i):number(i){}
		~A() {};
		int get_number()
		{
			return number;
		}
	protected:
		void set_number(int i) {number = i;}
	private:
		int number;
};

class B : private A
{
	public:
		B(int i) :A(i) {}

};

//protected继承：可以被1.该类中的函数、2.子类的函数、以及3.其友元函数访问。但不能被该类的对象访问。

class C :protected A
{
	public:
		C(int i) : A(i) {}
		int get_number(int i) {cout<<A::get_number()<<endl;}
		void set_number(int i) {A::set_number(i);}
};

int main()
{
	B b(10);
   //	b.get_number();  B继承A之后 所有protected /public 权限都变为private
	C c(10);
	c.get_number(10); // C继承A之后，A所有的protected /public 权限变为protected
	c.set_number(20);
	c.get_number(10);
	return 0;
}
