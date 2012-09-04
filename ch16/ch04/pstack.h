#ifndef _PSTACK_H
#define _PSTACK_H
#include <string.h>

template<class T,int rect=10>
class PStack
{
	int quantify;
	int next;
	T** storage;
	void inflate(int increase=rect);
	public:
	PStack():next(0),quantify(0),storage(0) {};
	~PStack();
	int add(T *element);
	T* operator[](int index);
	T* remove(int index);
	int count();
};

template<class T,int rect>
int PStack<T,rect>::add(T* element)
{
	if(next>=quantify)
	{
		inflate(rect);
	}

	storage[next++] = element;
	return (next-1);
}

template<class T, int rect>
PStack<T,rect>::~PStack()
{
	for(int i=0;i<next;i++)
	{
		delete storage[i];
		storage[i] = 0;
	}
}

template<class T,int rect>
T* PStack<T,rect>::operator[](int index)
{
	if(index>=0&&index<=next)
	{
		return storage[index];
	}
	else
	{
		return 0;
	}
}

template<class T,int rect>
T* PStack<T,rect>::remove(int index)
{
	T* v = operator[](index);
	if(v !=0)
	{
		storage[index]=0;
	}
	return v;
}

template<class T,int rect>
void PStack< T,rect>::inflate(int increase)
{
	const int psz = sizeof(T*);
	T** st=new T*[quantify+increase];
	memset(st,0,(quantify+increase)*psz);
	memcpy(st,storage,quantify*psz);
	quantify+=increase;
	delete []storage;
	storage = st;
}

#endif

