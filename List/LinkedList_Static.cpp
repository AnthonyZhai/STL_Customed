#include "LinkedList_Static.h"
using namespace std;
template <class T>
LinkedList_Static<T>::LinkedList_Static():first(NULL_VALUE),free(0)
{
	for(int i=0;i<CAPACITY;i++)
		LinkedList_Array[i].next=i+1;
	LinkedList_Array[CAPACITY-1].next=NULL_VALUE;
	emptyNodes=CAPACITY;
}

template <class T>
bool LinkedList_Static<T>::empty() const
{
	return (emptyNodes==CAPACITY);
}

template <class T>
int LinkedList_Static<T>::newNode(const T& item)
{
	if(emptyNodes<=0){
		cerr<<"LinkedList is full!"<<endl;
		exit(1);
	}
	int pos=free;
	free=LinkedList_Array[free].next;
	//先调整free再存值，不然造成free->next丢失
	if(first==NULL_VALUE)
		LinkedList_Array[pos].next=NULL_VALUE;
	else
		LinkedList_Array[pos].next=first;
	LinkedList_Array[pos].data=item;
	first=pos;
	--emptyNodes;
	return pos;
}

template <class T>
void LinkedList_Static<T>::deleteNode(int pos)
{
	if(pos<0||pos>=CAPACITY){
		cerr<<"Index out of bouds!"<<endl;
		return ;
	}
	if(first==NULL_VALUE){
		cerr<<"LinkedList if empty!"<<endl;
		return;
	}
	if(pos==first)
		first=LinkedList_Array[first].next;
	else{
		int curr=first,pre=first;
		while(LinkedList_Array[curr].data!=LinkedList_Array[pos].data){
			pre=curr;
			curr=LinkedList_Array[curr].next;
		}
		LinkedList_Array[pre].next=LinkedList_Array[curr].next;
	}
	LinkedList_Array[pos].next=free;
	free=pos;
	++emptyNodes;
}

template <class T>
int LinkedList_Static<T>::getLast() const
{
	int pos=first;
	while(pos!=NULL_VALUE)
		pos=LinkedList_Array[pos].next;
	return LinkedList_Array[pos].data;
}

template <class T>
int LinkedList_Static<T>::getFirst() const
{
	return LinkedList_Array[first].data;
}

template <class T>
bool LinkedList_Static<T>::isASC() const
{
	int pos=first,MIN=LinkedList_Array[first].data;
	while(pos!=NULL_VALUE){
		if(MIN>LinkedList_Array[pos].data)
			return false;
		pos=LinkedList_Array[pos].next;
	}
	return true;
}

template <class T>
int LinkedList_Static<T>::calcEmptyNodes() const
{
	return emptyNodes;
}

template <class T>
void LinkedList_Static<T>::display(ostream& out) const
{
	int pos=first;
	while(pos!=NULL_VALUE){
		out<<LinkedList_Array[pos].data<<" ";
		pos=LinkedList_Array[pos].next;
	}
}

template <class T>
ostream& operator << (ostream &out,const LinkedList_Static<T> &aList)
{
	aList.display(out);
	return out;
}

template <class T>
void LinkedList_Static<T>::show() const
{
	for(int i=0;i<CAPACITY;i++)
		cout<<LinkedList_Array[i].data<<" ";
	cout<<endl;
}
