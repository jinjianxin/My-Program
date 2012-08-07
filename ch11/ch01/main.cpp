#include <iostream>

struct Big
{
	char buf[100];
	int i;
	long g;
}B,B2;

Big big(Big b)
{
	b.i = 100;
	return b;
}

int main()
{
	B2 = big(B);
	return 0;
}
