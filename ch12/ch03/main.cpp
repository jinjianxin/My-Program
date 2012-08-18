#include <iostream>
#include <vector>

using namespace std;

class Obj
{
	static int i,j;
	public:
		void g() {cout<<i++<<endl;};
		void f() {cout<<j++<<endl;};
};	

int Obj::i = 0;
int Obj::j = 0;

class ObjContainer
{
	vector<Obj *> c;
	public:
	void add(Obj *obj) {c.push_back(obj);}
	friend class SmartPointer;
};

class SmartPointer
{
	ObjContainer& oc;
	int index;
	public:
	SmartPointer(ObjContainer& objc): oc(objc)
	{
		index = 0;
	}

	bool operator++()
	{
	
		cout<<"operator++"<<endl;
		if(index >=oc.c.size())
			return false;

		if(oc.c[++index] == 0)
			return false;

		return true;
	}

	bool operator++(int)
	{
		cout<<"operator++()"<<endl;
		return operator++();
	}

	Obj* operator->() const
	{
		return oc.c[index];
	}
};

int main()
{
/*	const int size = 10;	
	Obj o[size];
	ObjContainer oc;
	
	int i=0;
	for(i=0;i<10;i++)
	{
		oc.add(&o[i]);
	}

	SmartPointer sp(oc);

	do
	{
		sp->g();
		sp->f();
	}while(sp++);
*/
	return 0;
}
