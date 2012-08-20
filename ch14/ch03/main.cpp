#include <iostream>

using namespace std;

class Parent
{
	int i;
	public:
	Parent(int ii) : i(ii){
	cout<<"Parent(int ii)"<<endl;
	}

	Parent(const Parent& b) :i(b.i)
	{
		cout<<"Parent(const Parent& )"<<endl;
	}

	Parent():i(0) {};
	friend ostream& operator <<(ostream& os,const Parent& b)
	{
		return os<<"Parent:"<<b.i<<endl;
	}
};

class Member
{
	int i;
	public:
	Member(int ii): i(ii)
	{
		cout<<"Member(int ii)"<<endl;
	}

	Member(const Member& m): i(m.i)
	{
		cout<<"Member(const Member& m)"<<endl;
	}
	friend ostream& operator<<(ostream& os,const Member& m)
	{
		return os<<"Member"<<m.i<<endl;
	}
};

class Child : public Parent
{
	Member m;
	int i;
public:
	Child(int ii):i(ii),m(ii),Parent(ii)
	{
		cout<<"Child(int ii)"<<endl;
	}

	Child(Child& c):i(c.i),m(c.m),Parent(c)
	{
		cout<<"copy"<<endl;
	}

	friend ostream& operator<<(ostream& os,const Child& c)
	{
		return os<<(Parent&)c<<c.m<<"Child:"<<c.i<<endl;
	}
};

int main()
{
	Child c(10);
	Child c2 = c;
	cout<<c2;
	return 0;
}
