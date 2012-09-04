#include <iostream>
#include "pstack.h"
#include "autocounter.h"

using namespace std;

int main()
{
	PStack<AutoCounter> acStack;
//	AutoCounter *p = AutoCounter::create();
	for(int i=0;i<10;i++)
	{
		acStack.add(AutoCounter::create());
	}

	for(int j=0;j<5;j++)
	{
		delete acStack.remove(j);
	}


	return 0;
}
