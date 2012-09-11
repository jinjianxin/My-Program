#include "TPStash.h"
int main()
{
	PStash<int> s;

	for(int i=0;i<30;i++)
	{
		s.add(new int(i));
	}

	PStash<int>::iterator it = s.begin();

	it+=5;

	PStash<int>::iterator it2 = s.begin();
	it2+=15;

	for(;it!=it2;it++)
	{
		std::cout<<*it<<std::endl;
		delete it.remove();
	}

	for(it = s.begin();it !=s.end();it++)
	{
		if(*it)
		{
			cout<<*(*it)<<endl;
		}
	}

	return 0;
}
