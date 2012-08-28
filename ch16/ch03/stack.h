#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

template<class T>
class Stack
{
	struct Link
	{
		T *data;
		Link *next;
		Link(T *dat,Link *nxt):
			data(dat),next(nxt)
		{}

	}*head;
	public:
	Stack():head(0) {}
	~Stack()
	{
		while(head)
		{	
			delete pop();
		}
	}
	void push(T* dat)
	{
		head = new Link(dat,head);
	}

	T* speek() const
	{
		return head?head->data:0;
	}

	T* pop()
	{
		if(head ==0)
			return 0;
		T *result = head->data;
		Link *oldHead = head;
		head =head->next;
		delete oldHead;
		return result;
	}
};



#endif
