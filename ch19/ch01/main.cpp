#include <iostream>
#include <string>

using namespace std;

int main()
{
/*
 * 不能使用单个字符或者ASCII码来初始出化字符串
 * */
//	string s1('a');

/*
 *单个字符多个copy来初始化字符串
 */
	string s(5,'a');

	cout<<s<<endl;
	return 0;
}

