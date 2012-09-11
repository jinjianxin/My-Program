#ifndef TPSTASH_H
#define TPSTASH_H

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

template<class T,int incr=20>
class PStash
{
	int quantity;
	int next;
	T** storage;
	void inflate(int increate=incr);
	public:
	PStash():quantity(0),storage(0),next(0)
	{
		std::cout<<"PStashinit"<<std::endl;
	}
	~PStash();
	int add (T* element);
	T* operator[](int index) const;
	T* remove(int index);
	int cout() {return next;}
	class iterator;
	friend class iterator;
	class iterator
	{
		PStash& ps;
		int index;
		public:
		iterator(PStash& pStash):ps(pStash),index(0) {}
		iterator(PStash& pStash,bool ):ps(pStash),index(ps.next) {}
		iterator(const iterator& rv):ps(rv.ps),index(rv.index) {}
		iterator& operator=(const iterator& rv)
		{
			ps = rv.ps;
			index =rv.index;
			return *this;
		}

		iterator& operator++()
		{
			if(++index <=ps.next)
			{
				return *this;
			}
		}

		iterator& operator++(int)
		{
			operator++();
		}

		iterator& operator--()
		{
			if(--index >=0)
			{
				return *this;
			}
		}

		iterator& operator--(int)
		{
			operator--();
		}

		iterator& operator+=(int amount)
		{
			if(index+amount<ps.next && index+amount>=0)
			{
				std::cout<<"iterator operator+="<<std::endl;
			index +=amount;
			return *this;
			}
		}

		iterator& operator-=(int amount)
		{
			if(index-amount>=0 &&index-amount<ps.next)
			{
				index -+amount;
				return *this;
			}
		}

		iterator operator+(int amount) const
		{
			iterator ret(*this);
			index+=amount;
			return ret;
		}

		T* current() const
		{
			return ps.storage[index];
		}

		T* operator*() const
		{
			return current();
		}

		T* operator->()
		{
			return current;
		}

		T* remove()
		{
			std::cout<<"iterator remove"<<std::endl;
			return ps.remove(index);
		}

		bool operator==(const iterator& rv) const
		{
			return index == rv.index;
		}

		bool operator!=(const iterator& rv) const
		{
			return index!=rv.index;
		}
	};

	iterator begin() {return iterator(*this);}
	iterator end() {return iterator(*this,true);};
};

template<class T,int incr>
PStash<T,incr>::~PStash()
{
	for (int i=0;i<next;i++)
	{
		delete storage[i];
		storage[i]=0;
	}

	delete [] storage;
}

template<class T,int incr>
int PStash<T,incr>::add(T* element)
{
	if(next >= quantity)
	{
		inflate();
	}
	next++;
	storage[next++] = element;
	return next-1;
}

template<class T,int incr>
T *PStash<T,incr>::operator[](int index) const
{
	if(index>next)
	{
		return 0;
	}

	return storage[index];
}

template<class T,int incr>
T* PStash<T,incr>::remove(int index) 
{
	T *v = operator[](index);

	storage[index] = 0;
	return v;
}

template<class T,int incr>
void PStash<T,incr>::inflate(int increate)
{
	const int size = sizeof(T*);
	T** s = new T*[increate+quantity];
	memset(s,0,(increate+quantity)*size);
	memcpy(s,storage ,quantity*size);
	quantity +=increate;
	delete []storage;
	storage =s;
}

#endif

