#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

bool g15(int x)
{
	return x>15;
}

bool contains_e(const string& s)
{
	return s.find("s") != string::npos;
}

int main(int argc,char *argv[])
{
	{
	int a[] = {10,20,30};

	const size_t size = sizeof a / sizeof a[0];

	int b[size];

	copy(a,a+size,b);

	for(size_t i = 0;i<size;i++)
		assert(a[i] == b[i]);

	}

	{
	
		string a[] = {"read","my","libs"};
		const size_t size = sizeof a/sizeof a[0];

		string b[size];
		copy(a,a+size,b);

		assert(equal(a,a+size,b));
	}

	{
		int a[] = {10,20,30,45,25,12};
		const size_t size = sizeof a/sizeof a[0];
		vector<int> v1(a,a+size);
		vector<int> v2(size);
		copy(v1.begin(),v1.end(),v2.begin());
		assert(equal(v1.begin(),v1.end(),v2.begin()));
	}

	{
		int a[] = {10,20,30,45,25,12};
		const size_t size = sizeof a/sizeof a[0];
		vector<int> v1(a,a+size);
		vector<int> v2;
		copy(v1.begin(),v1.end(),back_inserter(v2));
		assert(equal(v1.begin(),v1.end(),v2.begin()));
	}


	{
		int a[] = {10,12,21,41,12,21,11,1,2,3,4,5,6,7,8,9};
		const size_t size =  sizeof a/sizeof a[0];
		int b[size];
		/**
		 *remove_copy_if 第四个参数为函数指针
		 */
		int *endb = remove_copy_if(a,a+size,b,g15);
		int *beginb = b;

		while(beginb !=endb)
		{
			cout<<*beginb++<<endl;
		}
	}


	{
		string a[] = {"read","my","libs"};
		const size_t size = sizeof a/sizeof a[0];

		string b[size];
		
		string *endb = replace_copy_if(a,a+size,b,contains_e,string("kiss"));
		string *beginb = b;

		while(beginb !=endb)
		{
			cout<<*beginb++<<endl;
		}

	}

	{
		ofstream ints("test.dat");	
		ints<<"1 2 3 4 5 6 7 8 9 56 8 45 41 78 45 87 18 15 54 52";
		ints.close();

		ifstream inf("test.dat");

		remove_copy_if(istream_iterator<int >(inf),
				istream_iterator<int>(),
				ostream_iterator<int>(cout,"\n"),g15
				);
	}
}
