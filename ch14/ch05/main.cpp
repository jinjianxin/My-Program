#include <iostream>
#include <math.h>

using namespace std;

class Point
{
	double x;
	double y;
	public:
	Point(double i,double j):x(i),y(j) {};
	void print()
	{
	}
};

class Figure
{
	Point center;
	public:
	Figure(double i,double j) :center(i,j) {}

	Point& location()
	{
		return center;
	}

	void move(Point p)
	{
		center = p;
		draw();
	}
	
	virtual void draw() = 0;
	virtual void  rotate(double) = 0; 
	void test() 
	{
		cout<<"Figure test"<<endl;
	}
};

class Circle : public Figure
{
	double radius;
	public:
	Circle(double i,double j,double r) :Figure(i,j),radius(r) {};

	void draw()
	{
		cout<<"draw Circle"<<endl;
	}

	void rotate(double)
	{
		cout<<"rotate Circle"<<endl;
	}

	double area()
	{
		double area = 3.14*(radius*radius);
		return area;
	}

	void test()
	{
		cout<<"Circle test"<<endl;
	}
};

class  Rectangle : public Figure
{
	public :
	Rectangle(double i,double j):Figure(i,j) {};

	void draw()
	{
		cout<<"draw Rectangle"<<endl;
	}

	void rotate(double) 
	{
		cout<<"rotate Rectangle double"<<endl;
	}
/*
 * 不能隐藏该函数
	void rotate()
	{
		cout<<"rotate Rectangle "<<endl;
	}*/
};


class A 
{
	public:
		A() {};
		~A(){};
		virtual void print()
		{
			cout<<" print A"<<endl;
		};
};

class B 
{
	public:
		B(){};
		~B(){};
		void print()
		{
			cout<<"print B"<<endl;
		}
};

class C : public A,public B
{
	public:
		C() {};
		~C() {};
		void print()
		{
			A::print();
			B::print();
		}
};


int main()
{
	Circle *c = new Circle(1.0,1.0,1.0);
	c->draw();
	cout<<c->area()<<endl;
	c->test();
	c->Figure::test();


	Figure *f = c;
	f->draw();
	f->rotate(1.0);
	f->test();
	//f->area(); 错误 ，area 不是Figure 的成员函数

	Rectangle *r = new Rectangle(1.0,1.0);

	Figure *g = r;
	g->draw();
	r->rotate(2.0);


	C *c1 = new C;
	c1->print();

	return 0;
}
