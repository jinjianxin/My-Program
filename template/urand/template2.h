#include <iostream>

namespace tp2
{

template <class T,size_t N>
class Array
{
	public:
	Array() {count = 0,data = new T[N];}
	~Array() {delete [] data;}
	private:
	T *data;
	size_t count;
	public:
	void push_back(const T& t)
	{
		data[count++] = t;
	}

	void pop_back()
	{
		if(count>0)
		{
			count--;
		}
	}

	T *begin() {return data;}
	T *end () 
	{
		return data+count;
	}
	
};

template <class T,size_t N,template<class,size_t> class Seq >
class Container
{
	Seq<T,N> seq;
	public:
	void append(const T& t) {seq.push_back(t);}
	T *begin() {return seq.begin();}
	T *end() {return seq.end();}
};
};
