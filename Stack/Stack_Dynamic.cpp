#include "Stack_Dynamic.h"
#include <cassert>
using namespace std;
template <class T>
Stack_Dynamic<T>::Stack_Dynamic(int max)
{
	assert(max>0);
	CAPACITY=max;
	Stack_Array=new(nothrow) T[CAPACITY];
	if(Stack_Array!=0)
		top=-1;
	else{
		cerr<<"No more mem to alloc stack!"<<endl;
		exit(1);
	}
}

template <class T>
Stack_Dynamic<T>::Stack_Dynamic(const Stack_Dynamic<T>& right)
:CAPACITY(right.CAPACITY),top(right.top)
{
	Stack_Array=new(nothrow) T[CAPACITY];
	if(Stack_Array!=0)
		for(int i=top;i>=0;i--)
			Stack_Array[i]=right.Stack_Array[i];
	else{
		cerr<<"No more mem to alloc stack!"<<endl;
		exit(1);
	}
}

template <class T>
const Stack_Dynamic<T>& Stack_Dynamic<T>::operator ==(const Stack_Dynamic<T>& right)
{
	if(this!=right){
		if(CAPACITY!=right.CAPACITY){
			delete []Stack_Array;
			CAPACITY=right.CAPACITY;
			top=right.top;
			Stack_Array=new(nothrow) T[CAPACITY];
			if(Stack_Array==0){
				cerr<<"No more mem to alloc!"<<endl;
				exit(1);
			}
		}
		for(int i=top;i>=0;i--)
			Stack_Array[i]=right.Stack_Array[i];
	}
	return *this;
}

template <class T>
Stack_Dynamic<T>::~Stack_Dynamic()
{
	delete []Stack_Array;
}

template <class T>
bool Stack_Dynamic<T>::empty() const
{
	return (top==-1);
}

template<class T>
void Stack_Dynamic<T>::push(const T& item)
{
	if(top==CAPACITY-1){
		cerr<<"Stack is full!"<<endl;
		return;
	}
	top++;
	Stack_Array[top]=item;
}

template <class T>
void Stack_Dynamic<T>::pop()
{
	if(top==-1){
		cerr<<"Stack is empty!"<<endl;
		return ;
	}
	top--;
}

template <class T>
T Stack_Dynamic<T>::getTop() const
{
	if(!empty())
		return Stack_Array[top];
	else{
		cerr<<"Stack is empty!Returning garbage value!"<<endl;
		T garbage;
		return garbage;
	}
}

template <class T>
void Stack_Dynamic<T>::display(ostream& out) const
{
	for(int i=top;i>=0;i--)
		out<<Stack_Array[i]<<" ";
}

template <class T>
ostream& operator <<(ostream& out,const Stack_Dynamic<T>& right)
{
	right.display(out);
	return out;
}