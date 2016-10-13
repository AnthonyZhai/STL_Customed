#include "LinkedList.h"
using namespace std;
template <class T>
LinkedList<T>::LinkedList():size(0),first(nullptr),back(nullptr){}

template <class T>
LinkedList<T>::~LinkedList()
{
	// while(first!=nullptr)
	// {
	// 	Node* pos=first;
	// 	first=first->next;
	// 	delete pos;
	// }
	for(int i=0;i<size;i++)
		pop();
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& right):size(right.size)
{
	first=back=nullptr;
	if(right.size!=0){
		Node* pos=right.first;
		while(pos!=nullptr){
			push(pos->data);
			pos=pos->next;
		}
	}
}

template <class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList& right)
{
	if(this!=right){
		if(right.size!=0){
			for(int i=0;i<size;i++)
				pop();
			Node* pos=right.first;
			while(pos!=nullptr){
				push(pos->data);
				pos=pos->next;
			}
		}
	}
	return *this;
}

template <class T>
void LinkedList<T>::display(ostream &out) const
{
	Node* pos=first;
	while(pos!=nullptr){
		out<<pos->data<<" ";
		pos=pos->next; 
	}
}

template <class T>
void LinkedList<T>::push(const T& item)
{
	insert(item,size);
}

template <class T>
void LinkedList<T>::pop()
{
	erase(size-1);
}

template <class T>
void LinkedList<T>::insert(const T& item,int pos)
{
	if(pos>size||pos<0){
		cerr<<"insert:Index out of bouds!"<<endl;
		exit(1);
	}
	else{
		Node* newNode=new Node;
		newNode->data=item;
		Node* curr=first;
		if(pos==0){
			newNode->next=first;
			first=newNode;
		}
		else{
			for(int i=0;i<pos-1;i++)
				curr=curr->next;
			newNode->next=curr->next;
			curr->next=newNode;
		}
		size++;
	}
}

template <class T>
void LinkedList<T>::erase(int pos)
{
	if(pos<0||pos>=size){
		cerr<<"erase:Index out of bouds!"<<endl;
		exit(1);
	}
	else
	{
		Node* curr=first;
		if(pos==0){
			first=first->next;
		}
		else{
			for(int i=0;i<pos-1;i++)
				curr=curr->next;
			Node* tmp=curr->next;
			curr->next=tmp->next;
			curr=tmp;
		}
		delete curr;
		size--;
	}
}

template <class T>
bool LinkedList<T>::empty() const
{
	return size==0;
}

template<class T>
int LinkedList<T>::rsize() const
{
	return size;
}

template <class T>
const T LinkedList<T>::rback() const
{
	Node* pos=first;
	while(pos!=nullptr)
		pos=pos->next;
	return pos->data;
}

template<class T>
ostream& operator <<(ostream &out,const LinkedList<T> &right)
{
	right.display(out);
	return out;
}