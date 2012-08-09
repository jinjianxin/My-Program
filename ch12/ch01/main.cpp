#include <iostream>

using namespace std;

class Integer
{
	public:
		Integer(int i) :number(i) { str = new char[100];};
		~Integer(){delete str;
		str= NULL;};
		Integer(const Integer& in):number(in.number)
		{
			str = new char[100];
		}
		const Integer operator+(const Integer& in) const
		{
			return Integer(in.number+number);
		}

		Integer& operator+=(const Integer& in)  
		{
			number += in.number;

			return *this;
		}
		
		Integer& operator-=(const Integer& in)
		{
			number-=in.number;
			return *this;
		}	
		int number;
		char *str;
};

int main()
{
	Integer a(10);
	cout<<a.number<<endl;
	Integer b(a);
	cout<<b.number<<endl;
	a+=b;
	cout<<a.number<<endl;
	cout<<(a+b).number<<endl;
	cout<<(a-=b).number<<endl;

	return 0;
}
