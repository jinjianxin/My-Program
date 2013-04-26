#include <iostream>
#include <vector>
#include "gromit.h"
#include "app.h"

int main(int argc,char *argv[])
{

	std::vector<Gromit*> dogs;

	for(int i=0;i<5;i++)
	{
		dogs.push_back(new Gromit(i));
	}

	apply(dogs,&Gromit::speak,1);
	apply(dogs,&Gromit::eat,2.0f);
	apply(dogs,&Gromit::sleep,'z',3.0);
	apply(dogs,&Gromit::sit);
}
