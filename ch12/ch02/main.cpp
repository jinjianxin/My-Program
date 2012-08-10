#include <iostream>

using namespace std;

class Integer
{
	public:
		Integer(int i);
		~Integer();
		/*+*/
		Integer operator+(const Integer& in);
		Integer operator+(const Integer& in) const;
//		const Integer operator+(const Integer& in) const;
//		/*-*/
		Integer operator-(const Integer& in);
		Integer operator-(const Integer& in) const;
		/* * */
		Integer operator*(const Integer& in);
		Integer operator*(const Integer& in) const;

		/* / */
		Integer operator/(const Integer& in);
		Integer operator/(const Integer& in) const;
	
		/*++*/
		Integer operator++();
		Integer operator++(int);

		/*--*/
		Integer operator--();
		Integer operator--(int);

		//Integer operator++() const; error
	
		int objectCount;
};

Integer::Integer(int i):
	objectCount(i)
{
}

Integer::~Integer()
{
}

Integer Integer::operator+(const Integer& in)
{
	return Integer(objectCount+in.objectCount);
}

Integer Integer::operator+(const Integer& in) const
{
	return Integer(objectCount+in.objectCount);
}
/*
const Integer Integer::operator+(const Integer& in) const
{
	return Integer(objectCount+in.objectCount);
}*/

Integer Integer::operator-(const Integer& in)
{
	return Integer(objectCount-in.objectCount);
}

Integer Integer::operator-(const Integer& in) const
{
	return Integer(objectCount-in.objectCount);
}

/*
Integer& Integer::operator+(const Integer& in)
{
	Integer a(objectCount+in.objectCount);
	Integer& b =a;
	return b;
}
*/

Integer Integer::operator*(const Integer& in)
{
	return Integer(objectCount*in.objectCount);
}

Integer Integer::operator*(const Integer& in) const
{
	return Integer(objectCount*in.objectCount);
}

Integer Integer::operator/(const Integer& in)
{
	return Integer(objectCount/in.objectCount);
}

Integer Integer::operator/(const Integer& in) const
{
	return Integer(objectCount/in.objectCount);
}

Integer Integer::operator++()
{
	++objectCount;
	return *this;
}

Integer Integer::operator++(int)
{
	objectCount++;
	return *this;
}

Integer Integer::operator--()
{
	--objectCount;
	return *this;
}

Integer Integer::operator--(int)
{
	objectCount--;
	return *this;
}

int main(int argc,char *argv[])
{
	Integer a(10);
	Integer b(5);
	

	cout<<"operator +"<<"\ta+b="<<((a+b)+b).objectCount<<endl;
	cout<<"operator -"<<"\ta-b="<<(a-b).objectCount<<endl;
	cout<<"operator *"<<"\ta*b="<<(a*b).objectCount<<endl;
	cout<<"operator /"<<"\ta/b="<<(a/b).objectCount<<endl;
	cout<<"operator a++"<<"\ta++="<<(a++).objectCount<<endl;
	cout<<"operator ++a"<<"\t++a="<<++a.objectCount<<endl;
	cout<<"operator a--"<<"\ta--="<<a--.objectCount<<endl;
	cout<<"operator --a"<<"\t--a="<<--a.objectCount<<endl;

	cout<<endl;

	/*const*/
	const Integer d(3);
	const Integer c(2);
	
	cout<<"operator +"<<"\tc+d="<<(c+d).objectCount<<endl;
	cout<<"operator -"<<"\tc-d="<<(c-d).objectCount<<endl;	
	cout<<"operator *"<<"\tc*d="<<(c*d).objectCount<<endl;
	cout<<"operator /"<<"\tc/d="<<(c/d).objectCount<<endl;
	return 0;
}
