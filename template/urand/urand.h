#include <bitset>
#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <iostream>


using namespace std;
/**
 *无类型模板参数
 */
template <size_t UpperBound >
class uRand
{
	bitset<UpperBound> used;
	public:
	uRand() {srand(time(0));}
	size_t operator()();
};

template <size_t UpperBound>
inline size_t uRand<UpperBound>::operator()()
{
	if(used.count() == UpperBound)
		used.reset();

	size_t newval;
	
	while(used[newval = rand()%UpperBound])
	{
		used[newval] = true;
	}
	return newval;
}
