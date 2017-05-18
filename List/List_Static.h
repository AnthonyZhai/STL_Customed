#include <iostream>
#ifndef LIST_STATIC_H
#define LIST_STATIC_H
const int CAPACITY=1024;
template <class T>
class List_Static{
public:
	List_Static();
	bool empty() const;
	void insert(T item,int pos);
	void erase(int pos);
	void display(std::ostream &out) const;
	template <class S>
	friend std::ostream & operator<< (std::ostream &out,const List_Static<S> &aList);
private:
	int size;
	T List_Array[CAPACITY];
};

#endif