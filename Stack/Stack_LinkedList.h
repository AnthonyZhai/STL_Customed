#include <iostream>
#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H
template <class T>
class Stack_LinkedList{
public:
	Stack_LinkedList();
	Stack_LinkedList(const Stack_LinkedList<T>&);
	const Stack_LinkedList<T>& operator =(const Stack_LinkedList<T>&);
	~Stack_LinkedList();
	void push(const T&);
	void pop();
	const T getTop() const;
	void display(std::ostream&) const;
	int getSize() const;
	bool empty() const;
	template <class S>
	friend std::ostream& operator <<(std::ostream&,const Stack_LinkedList<S>&);
private:
	class Node{
	public:
		T data;
		Node* next;
		Node(const T& value,Node * link=nullptr):data(value),next(link){}
	};
	Node* top;
	int size;
};
#endif