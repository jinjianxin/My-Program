#include <iostream>

using namespace std;

class HowMany
{
	public:
		HowMany() {objectCount++;};
		~HowMany() {objectCount-- ;cout<<"HowMany delete"<<objectCount<<endl;};
		static int objectCount;
		static HowMany printf_object_count(HowMany h) ;
};

int HowMany::objectCount = 0;

HowMany HowMany::printf_object_count(HowMany h)
{
	cout<<"objectCount="<<h.objectCount<<endl;

	return h;
}

class HowMany2
{
	string name;
	public:
		HowMany2(const string& id):name(id) {++objectCount;};
		~HowMany2() {--objectCount;cout<<"HowMany2::objectCount="<<objectCount<<endl;};
		HowMany2(const HowMany2& h):name(h.name)
	{
		name +="  copy";
		++objectCount;
		cout<<name<<endl;
	};
	static HowMany2 printf_object_count(HowMany2 h);
	static int objectCount;

};

int HowMany2::objectCount = 0;

HowMany2 HowMany2::printf_object_count(HowMany2 h)
{
	cout<<"objectCount="<<objectCount<<endl;
	return h;
}

int main()
{/*
	HowMany h;
	cout<<HowMany::objectCount<<endl;
	HowMany h2 = HowMany::printf_object_count(h);
	cout<<HowMany::objectCount<<endl;*/

	HowMany2 h3("id");
	cout<<HowMany2::objectCount<<endl;
	
	HowMany2 h4 = HowMany2::printf_object_count(h3);
	cout<<HowMany2::objectCount<<endl;

	HowMany2::printf_object_count(h4);
	cout<<"******************************"<<endl;

	return 0;
	
}
