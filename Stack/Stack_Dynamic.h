#include <iostream>
#ifndef STACK_DYNAMIC_H
#define STACK_DYNAMIC_H
template <class T>
class Stack_Dynamic{
public:
	Stack_Dynamic(int max=1024);
	Stack_Dynamic(const Stack_Dynamic<T>&);
	const Stack_Dynamic<T>& operator ==(const Stack_Dynamic<T>&);
	~Stack_Dynamic();
	bool empty() const;
	T getTop() const;
	void push(const T&);
	void pop();
	void display(std::ostream&) const;
	template <class S>
	friend std::ostream& operator<<(std::ostream &,const Stack_Dynamic<S>& );
private:
	int CAPACITY;
	int top;
	T * Stack_Array;
};
#endif