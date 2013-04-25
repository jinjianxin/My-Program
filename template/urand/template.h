#include <iostream>

/**
 *自定义模板类的模板参数
 */
namespace tp1
{

	/**
	 *模板参数
	 */
template <class T>
class Array
{
	enum {INIT = 10};
	public:
	Array() {count = 0,data = new T[capacity=INIT];}
	~Array() {delete [] data;}
	private:
	T *data;
	size_t capacity;
	size_t count;
	public:
	void push_back(const T& t)
	{
		if(count == capacity)
		{
			size_t newCap = capacity*2;
			T *newData = new T[newCap];
			for(int i =0;i<count;i++)
			{
				newData[i] = data[i];
			}

			delete []data;
			data = newData;
			capacity = newCap;
		}
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
/**
 *模板类
 */
template <class T,template<class> class Seq >
class Container
{
	Seq<T> seq;
	public:
	void append(const T& t) {seq.push_back(t);}
	T *begin() {return seq.begin();}
	T *end() {return seq.end();}
};
};
