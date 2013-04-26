#include <iostream>


class Gromit
{
	int arf;
	int totalBarks;
	public:
	Gromit(int arf =1 ) :arf(arf+1),totalBarks(0) {}
/*	void speak(int )
	{
		for(int i = 0;i<arf;i++)
		{
			std::cout<<"arf!";
			++totalBarks;
		}
		std::cout<<"\n";
	}
*/
	void speak(int ) const
	{
			std::cout<<"arf!";

		std::cout<<"\n";
	}


	char eat(float ) const
	{
		std::cout<<"eat"<<std::endl;
		return 'Z';
	}

	int sleep(char ,double) const
	{
		return 0;
	}

	void sit() const
	{
	}
};

