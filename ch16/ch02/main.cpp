#include <iostream>

using namespace std;

template<class T,int size=100>
class Array
{
	T array[size];
	public:
	T& operator [] (int index)
	{
		if(index>=0&&index<size)
		{
			return array[index];
		}
	}

	int length() {return size;}
};

class Number
{
	public:
	Number(float ff=0.1f):f(ff) {}
	Number& operator = (const  Number& number)  //此处必须使用const关键字，否则无法重载该运算符
	{
		cout<<number.f<<endl;
		f = number.f;
		return *this;
	}
/*	
	Number& operator = (const float i)
	{
		f = i;
		return *this;
	}
*/
	float f;
	operator float() const {return f;}
};

template<class T,int size=10>
class Holder
{
	Array<T,size> *np;
	public:
	Holder() :np(0) {}
	T& operator[](int i)
	{
		if(np == 0)
		{
			np = new Array<T,size>;
		}

		np->operator[] (i); //此处调用Array的[] 运算符
	}

	int length () const {return size;}
	~Holder() {delete np;};
};

int main()
{
	Holder<Number> is;
	for(int i=0;i<5;i++)
	{	
		is[i] = i; //此处先调用Holder的[]运算符，在调用 Number的= 运算符
	}

	return 0;
}
