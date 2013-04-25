#include <list>
#include <vector>

#include "urand.h"
#include "template.h"
#include "template2.h"
#include "template3.h"
#include "template4.h"

//默认模板参数
template <class T>
T sum(T *b,T *e,T init=T())
{
	while(b !=e)
	{
		init+=*b++;
	}

	return init;
}

template<class charT,size_t N>
basic_string<charT> bitsetToString(const bitset<N>& bs)
{
	/**
	 * 此处加上template关键字的作用是告诉编译器后面的是一个模板名称，不加此关键字
	 * 会将<解释为一个小于号，而不是一个模板
	 */
	return bs.template to_string<charT ,char_traits<charT>,allocator<charT> >();
}

int main(int argc,char *argv[])
{

	//无类型模板参数
	uRand<10> u;
	for(int i=0;i<20;i++)
	{
		std::cout<<u()<<' ';
	}

	cout<<endl;
	
	cout<<"*********************************************"<<endl;


	int a[] ={1,2,3};

	//默认模板参数
	cout<<sum(a,a+sizeof(a)/sizeof(a[0]))<<endl;

	//模板类型的模板参数
	
	cout<<"*********************************************"<<endl;
	tp1::Container<int ,tp1::Array> container;

	container.append(1);
	container.append(2);
	
	int *p = container.begin();

	while(p !=container.end())
	{
		cout<<*p++<<endl;
	}

	cout<<"*********************************************"<<endl;
	tp2::Container<int ,10 ,tp2::Array> container2;

	container2.append(3);
	container2.append(4);

	p = container2.begin();

	while(p !=container2.end())
	{
		cout<<*p++<<endl;
	}

	cout<<"*********************************************"<<endl;

	tp3::Container<int ,tp3::Array> container3;
	
	for(int i = 6;i>4;i--)
	{
		container3.append(i);
	}

	p = container3.begin();

	while(p != container3.end())
	{
		cout<<*p++<<endl;
	}

	cout<<"*********************************************"<<endl;

	tp4::Container<int ,vector> container4;

	container4.append(7);
	container4.append(8);

	for(vector<int >::iterator p=container4.begin();p != container4.end();++p)
	{
		cout<<*p<<endl;
	}

	cout<<"*********************************************"<<endl;

	tp4::Container<string ,vector> container5;

	container5.append("test");
	container5.append("test2");

	for(vector<string >::iterator p=container5.begin();p != container5.end();++p)
	{
		cout<<*p<<endl;
	}

	cout<<"*********************************************"<<endl;
	bitset<10> bs;

	bs.set(1);
	bs.set(5);

	cout<<bitsetToString<char>(bs)<<endl;

}
