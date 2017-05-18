#include "Stack_Static.h"
using namespace std;
template <class T>
Stack_Static<T>::Stack_Static():top(NULL_VALUE){}

template <class T>
void Stack_Static<T>::push(const T& item)
{
	if(top==CAPACITY-1){
		cerr<<"Stack if full!"<<endl;
		exit(1);
	}
	top++;
	Stack_Array[top]=item;

}

template <class T>
void Stack_Static<T>::pop()
{
	if(top==NULL_VALUE){
		cerr<<"Stack if empty!"<<endl;
		exit(1);
	}
	top--;
}

template <class T>
bool Stack_Static<T>::empty() const
{
	return (top==NULL_VALUE);
}

template <class T>
T Stack_Static<T>::getTop() const
{
	if(!empty())
		return Stack_Array[top];
	else{
		cerr<<"Stack is empty!Returning garbage value"<<endl;
		T garbage;
		return garbage;
	}
}

template <class T>
void Stack_Static<T>::display(ostream& out) const
{
	for(int i=top;i>NULL_VALUE;i--)
		out<<Stack_Array[i]<<" ";
}

template <class T>
ostream& operator<< (ostream& out,const Stack_Static<T>& right)
{
	right.display(out);
	return out;
}