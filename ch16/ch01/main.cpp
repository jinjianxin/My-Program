#include <iostream>

using namespace std;

template<class T>
class Array{
	enum{size = 100};
	T A[size];
	public:
	T& operator[] (int index)  //此处的运算符重载既可以取得A的值也可以给A赋值
	{
		if(index>=0&&index<size)
		{
			cout<<index<<endl;
			return A[index];
		}
	}
};

int main()
{
	Array<int> ia;
	Array<float> fa;
	for(int i=0;i<20;i++)
	{
		ia[i] = i;
		fa[i] = 3.14*i;

	}

	return 0;
}
