#include <iostream>

using namespace std;

unsigned short Hash(void *p)
{
	return 1;
}

class A
{
	int a;
};

class B
{
	int b;
};


class Parents
{
	public:
		Parents(string n="parent") {name = n;}
		virtual ~Parents() {}
		string name;
		virtual void speek()
		{
			cout<<"Parents::speek"<<name<<endl;
		}

		virtual void work()
		{
			cout<<"Parents::work"<<endl;
		}
};

class Children : public Parents
{
	public:
		Children(string n="children") {children= n;}
		string children;
		virtual void speek() 
		{
			cout<<"Children::speek()="<<children<<endl;
		}

		void study()
		{
			cout<<"Children::study()"<<endl;
		}

};


int main()
{
	typedef unsigned short(*FuncPointer)(void *);
	FuncPointer fp = Hash; //可以正确转换

	int a[10];
	const int *ch=a;
	char chArray[4] = {'a','b','c','d'};

	fp = reinterpret_cast<FuncPointer> (ch); //可以编译通过，但是不能正常运行
	ch = reinterpret_cast<int *> (chArray) ; //可以正常编译

	A *a_instance  = new A;
	B *b_instance = reinterpret_cast< B *> (a);
	
	Children *daugther = new Children();
	Parents * mother = static_cast<Parents *> (daugther);

	Parents *parents = new Parents();
	Children *children = static_cast<Children *> (parents);  //可以正常转换，但是不安全

	const int constant = 21;
	const int* const_p = &constant;
	int* modifier = const_cast<int*>(const_p);
	*modifier = 7;


	Children *son_d = new Children("weiwei");
	Parents *mother_d = dynamic_cast<Parents *> (son_d);

	mother_d->speek();
	mother_d->work();
//	mother_d->study();	error 不能调用子类的方法

	cout<<"********************************************"<<endl;
	Children *son_s = new Children("weiwei_s");
	Parents *mother_s = static_cast<Parents *> (son_s);
	mother_s->speek();
	mother_s->work();

	Parents *mother_m = new Parents("ll");
	Children *son_m = dynamic_cast<Children *> (mother_m);

	if(son_m)
	{
		son_m->speek();
		son_m->work();
	}
	else
	{
		cout<<"son_m is NULL"<<endl;
	}


}
