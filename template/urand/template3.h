#include <iostream>

/**
 *自定义模板类型的模板参数，模板参数有默认值
 */

namespace tp3
{

	/**
	 *模板参数，带一个默认参数
	 */
template <class T,size_t N = 10>
class Array
{
	public:
	Array() {
		count = 0,data = new T[N];}
	~Array() {delete [] data;}
	private:
	T *data;
	size_t count;
	public:
	void push_back(const T& t)
	{
		if(count<N)
		{
			data[count++] = t;
		}
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

/**
 *模板类所带的模板参数有默认值
 */

template <class T,template<class,size_t N = 10> class Seq >
class Container
{
	Seq<T> seq;
	public:
	void append(const T& t) {seq.push_back(t);}
	T *begin() {return seq.begin();}
	T *end() {return seq.end();}
};
};
