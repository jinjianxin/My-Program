#include <iostream>

using namespace std;

template<class T,int size=10>
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
//	explicit Number(float ff=0.1f):f(ff) {cout<<"number init"<<endl;}
    Number(float ff=0.1f):f(ff) {cout<<"number init float"<<endl;} // 此处不能加上explicit关键字，否则无法转换
//	Number(int i = 0):ii(i)  {cout<<"number init int"<<endl;};

	Number& operator = (const  Number& number)  //此处必须使用const关键字，否则无法重载该运算符
	{
		f =number.f;
		return *this;
	}
	float f;
	operator float() const {return f;}
};

template<class T,int size=5> //只为一种类型生成一个实例
class Holder
{
	Array<T,size> *np;
	public:
	Holder() :np(0) {}
	T& operator[](int i)
	{
		if(np == 0)
		{
			np = new Array<T,size>;  //懒惰初始化，只有等调用时在初始化，
		}
	
		np->operator[] (i); //此处调用Array的[] 运算符	
	}
	

	int length () const {return size;}
	~Holder() {delete np;};
};

int main()
{
	Holder<Number> is;
	for(int i=0;i<1;i++)
	{	
		is[i] =i; // 编译器将i隐式转化为number的对象  调用Holder的[]运算符，在调用Number的= 运算符  讲i 赋值给is[i]
	}

	return 0;
}
