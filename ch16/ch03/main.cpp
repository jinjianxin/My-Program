#include <fstream>
#include "stack.h"


int main()
{

	Stack<string> stringStack;
	ifstream stream("main.cpp");
	
	string line;

	while(getline(stream,line))
	{
//		cout<<line<<endl;
		stringStack.push(new string(line));
	}

	string *s;

	for(int i=0;i<10;i++)
	{
		s = stringStack.pop();
		cout<<*s<<endl;
		delete s;
	}

	return 0;
}
