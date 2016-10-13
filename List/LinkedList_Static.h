#include <iostream>
#ifndef LINKEDLIST_ARRAY_H
#define LINKEDLIST_ARRAY_H
const int NULL_VALUE=-1;
const int CAPACITY=1024;
template <class T>
class LinkedList_Static{
private:
	struct Node{
		T data;
		int next;
	};
public:
	LinkedList_Static();
	bool empty() const;
	int newNode(const T&);
	void deleteNode(int);
	bool isASC() const;
	int getLast() const;
	int getFirst() const;
	int calcEmptyNodes()const;
	void display(std::ostream&) const;
	template <class S>
	friend std::ostream & operator<< (std::ostream &out,const LinkedList_Static<S> &aList);
	void show()const;
private:
	Node LinkedList_Array[CAPACITY];
	int free;
	int first;
	int emptyNodes;
};
#endif