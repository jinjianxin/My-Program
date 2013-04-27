#ifndef _SORT_H
#define _SORT_H

#include <vector>

using std::size_t;

template <class T>
class Sort : public std::vector<T>
{
	public:
		void sort();
};

template <class T>
void Sort<T>::sort()
{
	for(size_t i = this->size();i>0;i--)
		for(size_t j = 1;j<i;j++)
		{
			if(this->at(j-1)>this->at(j))
			{
				T t = this->at(j-1);
				this->at(j-1) = this->at(j);
				this->at(j) = t;
			}
		}
}


template <class T>
class Sort<T*>: public std::vector<T*>
{
	public:
		void sort();
};

template <class T>
void Sort<T*>::sort()
{
	for(size_t i = this->size();i>0;i--)
		for(size_t j = 1;j<i;j++)
		{
			if(*this->at(j-1)>*this->at(j))
			{
				T *t = this->at(j-1);
				this->at(j-1) = this->at(j);
				this->at(j) = t;
			}
		}
}

template <> inline void Sort<char*>::sort()
{
	for(size_t i = this->size();i>0;i--)
		for(size_t j = 1;j<i;j++)
		{
			if(strcmp(this->at(j-1), this->at(j))>0)
			{
				char *t = this->at(j-1);
				this->at(j-1) = this->at(j);
				this->at(j) = t;
			}
		}
}

#endif
