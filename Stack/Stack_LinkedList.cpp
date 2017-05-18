#include "Stack_LinkedList.h"
#include <cassert>
using namespace std;
template <class T>
Stack_LinkedList<T>::Stack_LinkedList():top(nullptr),size(0){}

template <class T>
Stack_LinkedList<T>::Stack_LinkedList(const Stack_LinkedList<T>& right)
{
	top=0;
	if(!right.empty()){
		top=new Stack_LinkedList::Node(right.getTop());
		Stack_LinkedList::Node* first=top,
		*curr=right.top->next;
		while(curr!=nullptr){
			first->next=new Stack_LinkedList<T>::Node(curr->data);
			first=first->next;
			curr=curr->next;
			size++;
		}
	}
}

template <class T>
const Stack_LinkedList<T>& Stack_LinkedList<T>::operator=(const Stack_LinkedList<T>& right)
{
	if(this!=right){
		this->~Stack_LinkedList();
		if(right.empty()){
			top=0;
			size=0;
		}
		else{
			size=right.size;
			top=new Stack_LinkedList<T>::Node(right.top());
			Stack_LinkedList::Node* first=top,
			*curr=right.top->next;
			while(curr!=nullptr){
				first->next=new Stack_LinkedList<T>::Node(curr->data);
				first=first->next;
				curr=curr->next;
			}
		}
	}
	return *this;
}

template <class T>
void Stack_LinkedList<T>::push(const T& item)
{
	top=new Stack_LinkedList<T>::Node(item,top);
	size++;
}

template <class T>
Stack_LinkedList<T>::~Stack_LinkedList()
{
	Stack_LinkedList<T>::Node* curr=top,*next;
	while(curr!=nullptr){
		next=curr->next;
		delete curr;
		curr=next;
	}
}

template <class T>
void Stack_LinkedList<T>::pop()
{
	if(!empty()){
		Stack_LinkedList::Node* curr=top;
		top=curr->next;
		delete curr;
		size--;
	}
	else{
		cerr<<"Stack is empty!"<<endl;
	}
}

template <class T>
const T Stack_LinkedList<T>::getTop() const
{
	if(!empty()){
		return top->data;
	}
	else{
		cerr<<"Stack is empty!Returning garbage value"<<endl;
		T garbage;
		return garbage;
	}
}

template <class T>
void Stack_LinkedList<T>::display(ostream& out) const
{
	Stack_LinkedList::Node* curr=top;
	while(curr!=nullptr){
		out<<curr->data<<" ";
		curr=curr->next;
	}
}

template <class T>
bool Stack_LinkedList<T>::empty() const
{
	return (top==nullptr);
}

template <class T>
int Stack_LinkedList<T>::getSize() const
{
	return size;
}

template <class T>
ostream& operator <<(ostream& out,const Stack_LinkedList<T>& right)
{
	right.display(out);
	return out;
}
