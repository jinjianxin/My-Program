#include <iostream>
#include <sstream>

using namespace std;

class A
{
	public:
		virtual ~A() {};
		virtual void print(ostream& ) const = 0;
};

class B
{
	public:
		virtual ~B() {};
		virtual int toInt() const = 0;
};

class C
{
	public:
		virtual ~C() {};
		virtual string toString() const = 0;
};


class Test : public A ,public B,public C
{
	public:
		Test(int data) : number(data) {}
	void print(ostream&) const
	{
		cout<<"Test "<<"A";
	}

	int toInt() const 
	{
		return number;
	}

	string toString() const 
	{		
		return "test";
	}

	int number;
};

void print(A& a)
{
	a.print(cout);
	cout<<endl;
}

void toInt(B& b)
{
	cout<<b.toInt()<<endl;
}

void toString(C& c)
{
	cout<<c.toString()<<endl;
}

template <class A>
void testPrint(const A& a)
{
	a.print(cout);
	cout<<endl;
}

/**
 *	template <class B>
 *	void testToint( B& b) const 
 *	{
 *		cout<<b.toInt()<<endl;
 *	}
 * 此处出现编译错误，非成员函数不能使用const和volatile限定，此外静态函数不能使用const限定
 * 出现的编译错误如下：
 * error: non-member function 'void testToint(B&)' cannot have cv-qualifier
 * 此处的cv 限定符就是指const和volatile
 */

template <class B>
void testToint( B& b) 
{
	cout<<b.toInt()<<endl;
}

template <class C>
void testTostring(C& c)
{
	cout<<c.toString()<<endl;
}

int main(int argc,char *argv[])
{
	Test *test = new Test(2);

	print(*test);
	toInt(*test);
	toString(*test);

	testPrint(*test);
	testToint(*test);
	testTostring(*test);
}
