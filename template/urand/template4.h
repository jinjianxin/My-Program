#include <iostream>

/**
 *标准容器作为模板类型的模板参数
 */
namespace tp4{


	/**
	 *模板类所带的模板为一个标准容器
	 */
template <class T,template<class U,class = allocator<U> > class Seq >
class Container
{
	Seq<T> seq;
	public:
	void append(const T& t) {seq.push_back(t);}
	/**
	 *此处必须加typename  关键字，否则会认为Seq<T>::iterator表达式为一个新类型
	 */
	typename Seq<T>::iterator  begin() {return seq.begin();}
	typename Seq<T>::iterator end() {return seq.end();}
};
};
