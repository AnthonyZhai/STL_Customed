#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <class T>
class LinkedList{
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList&);
	const LinkedList& operator=(const LinkedList&);
	void display(std::ostream&)const;
	void push(const T&);
	void pop();
	void erase(int);
	void insert(const T&,int);
	bool empty() const;
	int rsize() const;
	const T rback() const;
	template <class S>
	friend std::ostream& operator << (std::ostream&,const LinkedList<S>&);
private:
	int size;
	class Node{
	public:
		T data;
		class Node* next;
	};
	Node* first;
	Node* back;
};
#endif

