#include <iostream>
#ifndef STACK_STATIC_H
#define STACK_STATIC_H
const int CAPACITY=1024;
const int NULL_VALUE=-1;
template <class T>
class Stack_Static{
public:
	Stack_Static();
	bool empty() const;
	void push(const T&);
	void pop();
	T getTop() const;
	void display(std::ostream&) const;
	template <class S>
	friend std::ostream& operator <<(std::ostream &,const Stack_Static<S>&);
private:
	int top;
	T Stack_Array[CAPACITY];
};
#endif