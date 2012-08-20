#include <iostream>

using namespace std;

#define CLASS(ID) class ID {\
	public:\
	ID(int) {cout<<#ID<<"constructor"<<endl;}\
    ~ID() {cout<<#ID<<"destrouctor"<<endl;}\
	};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

class Derived1 : public Base1
{
	Member1 m1;
	Member2 m2;
	public:
	Derived1(int):m2(1),m1(1),Base1(3) {cout<<"Derived1 constructor"<<endl;}
	~Derived1() {cout<<"Derived1 destrouctor"<<endl;}
};

class Derived2 : public Derived1
{
	Member3 m3;
	Member4 m4;
	public:
	Derived2() :m3(2),m4(4),Derived1(4) {cout<<"Derived2 constructor"<<endl;};
	~Derived2() {cout<<"Derived2 destrouctor"<<endl;};
};

int main()
{
	Derived2 d2;
	return 0;
}
