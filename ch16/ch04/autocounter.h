#ifndef _AUTOCOUNTER_H
#define _AUTOCOUNTER_H
#include <iostream>
#include <set>

class AutoCounter
{
	static int count;
	int id;
	class CleanCheck
	{
		std::set<AutoCounter *> trace;
		public:
		void add(AutoCounter* ap)
		{
			trace.insert(ap);
		}

		void remove(AutoCounter *ap)
		{
			if(trace.erase(ap) ==1)
			{

			}
		}

		~CleanCheck()
		{
			if(trace.size() ==0)
			{
			}
		}
	};
	static CleanCheck verifier;
	AutoCounter():id(count++)
	{
		std::cout<<"AutoCounter init"<<std::endl;
		verifier.add(this);
	}
	AutoCounter(const AutoCounter&);
	void operator=(const AutoCounter&);
	public:
	static AutoCounter* create()
	{
		return new AutoCounter();
	}

	~AutoCounter()
	{
		verifier.remove(this);
	}
};


#endif
