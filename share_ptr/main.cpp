#include <boost/shared_ptr.hpp>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace boost;
using namespace std;

#define config

class A
{
	shared_ptr<int > no_;
	public:
	A(shared_ptr<int> no):no_(no) {};
	void  value(int i)
	{
		*no_ = i;
	}

};

class B
{
	shared_ptr<int> no_;
	public:
	B(shared_ptr<int> no) : no_(no) {};
	int value() const
	{
		return *no_;
	}
};

class TestBase
{
	public:
		//TestBase(){};
	    ~TestBase() {cout<<"delete TestBase"<<endl;};
		virtual void test() = 0;
};

class Test : public TestBase
{
	public:
		Test():TestBase() {cout<<"init"<<endl;};
		~Test(){cout<<"delete"<<endl;};
	void test()
	{
		cout<<"test"<<endl;
	};
};

shared_ptr<TestBase> create()
{
	shared_ptr<TestBase> p(new Test());
	return p;

}

class FileClose
{
	public:
	void operator()(FILE *file)
		{
			if(file !=0)
			{
				fclose(file);
				cout<<"file close"<<endl;
			}
		}
};

class C
{
	public:
		void operator()(Test *test)
		{
			cout<<"*********************c operator"<<endl;
		};
};

class TestDelete
{
	class Delete
	{
		public:
			void operator()(TestDelete *p)
			{
				cout<<"***************************Delete"<<endl;
				delete p;
			}
	};

	public:
	static shared_ptr<TestDelete> create()
	{
		shared_ptr<TestDelete> p(new TestDelete(),TestDelete::Delete());

		return p;
	}

protected:
	~TestDelete() {};
};

int main()
{ 
	shared_ptr<int > tmp(new int(14));

	A a(tmp);
	B b(tmp);

	cout<<b.value()<<endl;
	a.value(28);
	cout<<b.value()<<endl;

	typedef	vector<shared_ptr<TestBase> > container_type;
	typedef container_type::iterator iterator;

#ifdef config
	container_type *container = new container_type;
	container_type& type = *container;

	int i = 0;
	for(i=0;i<10;i++)
	{
//		type.push_back(create());
//		type->push_back(create()) ; //error
		container->push_back(create());
	}

	iterator end=container->end();
	for (iterator it=container->begin();it!=end;++it) {	
		(*it)->test();
	}
	
	delete container;
	container = 0;

#else

	container_type container;

	int i = 0;
	for(i=0;i<10;i++)
	{
//		type.push_back(create());
//		type->push_back(create()) ; //error
		container.push_back(create());
	}

	iterator end=container.end();
	for (iterator it=container.begin();it!=end;++it) {	
		(*it)->test();
	}

#endif

	FILE *f = fopen("main.cpp","rb");

	if(f == 0)
	{
		cout<<"Open main.cpp error"<<endl;
		exit(1);
	}

	shared_ptr<FILE> file(f,FileClose());
//	shared_ptr<FILE> file(f,&fclose);

	fseek(file.get(),42,SEEK_SET);


//	fseek(&*file,42,SEEK_SET);

	/*shared_ptr(FILE) file(f,&fclose);
	fseek(&*file,42,SEEK_SET);
	*/

	cout<<"\nclose"<<endl;

//	C *c = new C;
	shared_ptr<TestBase> mm(new Test(),C());

	shared_ptr<TestDelete> p = TestDelete::create();

	return 0;
}



