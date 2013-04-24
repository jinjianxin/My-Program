#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(int argc ,char *argv[])
{
    const int SZ = 100;
    char buf[SZ];
    {

        ifstream in("main.cpp"); //此处加上头文件fstream 否则编译出错
		ofstream out("main.out");

        int i = 0;

        while(in.get(buf,SZ))
        {
            in.get();
            cout<<buf<<endl;
            out<<i++<<":"<<buf<<endl;
        }
    }

	istringstream s("4 12.2 this is test  15 test");
	int i;
	float f;
	s>>setw(2)>>i>>f;
	string str1,str2;
	s>>str1>>str2;

	cout<<i<<"\t"<<f<<"\t"<<str1<<"\t"<<str2<<endl;
/*
    {

        ifstream in("main.cpp");

        int i = 0;

        while(in.getline(buf,SZ))
        {
            cout<<buf<<endl;
            //	cout<<i++<<":"<<endl;
        }
    }
*/

}
