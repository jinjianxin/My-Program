#include <iostream>
#include <cassert>
#include <typeinfo>


using namespace std;

class Simplay
{
	public:
		virtual void happy() {}
		virtual void joy() {cout<<"joy"<<endl;}
		virtual ~Simplay() {}
	
};

int main(int argc,char *argv[])
{
	void* v = new Simplay();
	/**
	 *此处编译错误,dynamic_cast只能用在类型直接转化
	 */
//	Simplay *s = dynamic_cast<Simplay *>(v);
	Simplay *s = static_cast<Simplay *>(v);
	cout<<typeid(*s).name()<<endl;
	s->joy();
}
