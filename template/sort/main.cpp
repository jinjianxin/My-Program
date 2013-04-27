#include <string.h>
#include "sort.h"
#include "../urand/urand.h"

using namespace std;

int main(int argc,char *argv[])
{
	Sort<int > s;

	uRand<47> urand;

	for(int i = 0;i<15;i++)
	{
		s.push_back(urand());
	}

	for(size_t i=0;i<15;i++)
	{
		cout<<s[i]<<"\t";
	}
	cout<<"\n";

	s.sort();

	for(size_t i=0;i<15;i++)
	{
		    cout<<s[i]<<"\t";
	}

	cout<<"\n";

	Sort<string* > ss;

	ss.push_back(new string("test"));
	ss.push_back(new string("est"));

	for(size_t i=0;i<2;i++)
		cout<<*ss[i]<<"\t";
	cout<<"\n";

	Sort<char* > sc;

	char *tmp = "test";

	sc.push_back((char *)("test"));
	sc.push_back((char *)("tes"));

	for(size_t i=0;i<2;i++)
		    cout<<*sc[i]<<"\t";
	cout<<"\n";

}
