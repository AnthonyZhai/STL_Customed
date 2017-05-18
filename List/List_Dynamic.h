#include <iostream>
#ifndef LIST_DYNAMIC_H
#define LIST_DYNAMIC_H
template <class T>
class List_Dynamic{
public:
	List_Dynamic(int maxSize=1024);
	List_Dynamic(const List_Dynamic&);
	const List_Dynamic& operator =(const List_Dynamic& right);
	~List_Dynamic();
	bool empty() const;
	void insert(T item,int pos);
	void erase(int pos);
	void display(std::ostream &out) const;
	template <class S>
	friend std::ostream & operator<< (std::ostream &out,const List_Dynamic<S> &aList);
private:
	int capacity;
	int size;
	T* List_Array;
};
#endif