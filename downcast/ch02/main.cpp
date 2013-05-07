#include <iostream>
#include <cassert>
#include <typeinfo>

using namespace std;

class B1
{
public:
	virtual ~B1() {};
};

class B2
{
public:
	virtual ~B2() {};
};

class MI : public B1,public B2 {};
class Mi2 : public MI {};

int main(int argc,char *argv[])
{
	B2 *b2 = new MI();

	Mi2 *m2 = dynamic_cast<Mi2 *>(b2);
	MI *mi = dynamic_cast<MI*>(b2);
	B1 *b1 = dynamic_cast<B1*>(b2);

	assert(typeid(b2) != typeid(Mi2 *));
	assert(typeid(b2) == typeid(B2 *));
	
	delete b2;
}
