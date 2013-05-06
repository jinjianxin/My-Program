#include <deque>
#include <list>
#include <vector>
#include <iostream>


using namespace std;

template<typename Container>
void print(Container& c,char *title = "")
{
	cout<<title<<":"<<endl;
	if(c.empty())
	{
		cout<<"(empty)"<<endl;
		return ;
	}

	typename Container::iterator it;
	for(it = c.begin(); it !=c.end();it++)
	{
		cout<<*it<<" ";
	}

	cout<<endl;

	cout<<"size = "<<c.size()<<"\t"
		<<"max_size = "<<c.max_size()<<"\t"
		<<"front = "<<c.front()<<"\t"
		<<"back = "<<c.back()<<"\t"
		<<endl;

}


template<typename ContainerOfInt>
void basicOps(char *s)
{
	cout<<"--------------------"<<s<<"---------------------"<<endl;
	typedef ContainerOfInt CType;

	CType c1;
	print(c1,"c1 afterdefault constructor");

	CType c2(10,1);
	print(c2,"c2 afterdefault constructor(10 1)");

	int ia[] = {1,2,3,4,5,6,7,8,9,10};
	const int IASZ = sizeof(ia)/sizeof(*ia);

	CType c3(ia,ia+IASZ);
	print(c3,"c3 afterdefault constructor(iter iter)");

	CType c4(c2);
	print(c4,"c4 after copy-constructor(c2)");

	c1 = c2;
	print(c1,"c1 operator =c2");

	/**
	 *重新赋值
	 */
	c1.assign(ia,ia+IASZ);
	print(c1,"c after assign(iter iter)");

	cout<<"c using reverce iterator"<<endl;

	typename CType::reverse_iterator rit = c1.rbegin();

	while(rit !=c1.rend())
	{
		cout<<*rit++<<" ";
	}

	cout<<endl;

	/**
	 *重置容器大小
	 */
	c1.resize(4);
	print(c1,"c1 after resize(4)");

	c1.push_back(47);
	print(c1,"c1 after push_back(47)");

	c1.pop_back();
	print(c1,"c1 after pop_back");

	typename CType::iterator it = c1.begin();
	++it;
	++it;
	c1.insert(it,74);
	print(c1,"c1 after insert (it 74) ");

	it = c1.begin();
	++it;
	c1.insert(it,3,96);
	print(c1,"c1 after insert (it 3 96)");

	it = c1.begin();
	++it;
	c1.insert(it,c3.begin(),c3.end());
	print(c1,"c1 after insert (it c3.begin(),c3.end())");

	it = c1.begin();
	it++;
	it++;
	/**
	 *清楚序列中的一个元素
	 */
	c1.erase(it);
	print(c1,"c1 after erase");

	typename CType::iterator it2 = it = c1.begin();
	++it;
	++it2;
	++it2;
	++it2;
	++it2;
	++it2;

	c1.erase(it,it2);
	print(c1,"c1 after erase(it,it2)");


	/**
	 *在两个容器间交换任何东西
	 */
	c1.swap(c2);
	print(c1,"c1 after swap(c2)");

	c1.clear();
	print(c1,"c1 after clear");
}

int main(int argc,char *argv[])
{

	basicOps<vector<int> >("vector");
	basicOps<deque<int> >("deque");
	basicOps<deque<int> >("list");

}
