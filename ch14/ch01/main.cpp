#include <iostream>

using namespace std;

class X
{
	public:
		X(int i);
		~X();
		void set(int i);
		void changed();
		int read();
		int parmute();
		int number;
};

class Y : public X
{
	public:
		Y(int i);
		~Y();
		void set();
		int parmute();
		int number ;
};

X::X(int i)
{
	number = i;
}

X::~X()
{
}

void X::set(int i)
{
	number = i;
}

void X::changed()
{
}

int X::read()
{
	return number;
}

int X::parmute()
{
	return number*number;
}

Y::Y(int i): X(i)
{
	number = i;
}

Y::~Y()
{
}

void Y::set()
{
	cout<<"y.set()"<<endl;
	X::set(number);
	cout<<X::parmute()<<endl;
	cout<<parmute()<<endl;
}

int Y::parmute()
{
	return number*number;
}

int main()
{
	Y y(7);
	cout<<y.parmute()<<endl;
	y.set();
	return 0;
}
