#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using std::sqrt;

class Sievce
{
	string sievceChar;
	public:
	Sievce():sievceChar(50,'p') {}
	void run()
	{
		findPerimes();
		testPerimes();
	}

	void findPerimes()
	{
		sievceChar.replace(0,2,"NN");
		cout<<sievceChar<<endl;
		size_t sivceSize = sievceChar.size();
		int root = int(sqrt(double(sivceSize)));
		for(int i=2;i<=root;++i)
		{
			for(size_t factor = 2;factor*i<sivceSize;++factor)
			{
				sievceChar[factor*i]='N';
			}
		}

		cout<<sievceChar<<endl;
	}

	void isPerimes()
	{
	}
	void testPerimes()
	{
		size_t i =sievceChar.find('p');
	}
};

int main()
{
	Sievce t;
	t.run();

	return 0;
}
