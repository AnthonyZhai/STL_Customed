#include "List_Static.h"
using namespace std;
template <class T>
List_Static<T>::List_Static():size(0){}

template <class T>
bool List_Static<T>::empty() const
{
	return size==0;
}

template <class T>
void List_Static<T>::insert(T item,int pos)
{
	if(size==CAPACITY){
		cerr<<"No more space for insertion!"<<endl;
		exit(1);
	}
	if(pos<0||pos>size){
		cerr<<"Index out of bouds!"<<endl;
		return;
	}
	for(int i=size;i>pos;i--){
		List_Array[i]=List_Array[i-1];
	}
	List_Array[pos]=item;
	size++;
}

template <class T>
void List_Static<T>::erase(int pos)
{
	if(size==0){
		cerr<<"List is empty"<<endl;
		exit(1);
	}
	if(pos<0||pos>=size){
		cerr<<"Index out of bouds"<<endl;
		return;
	}
	for(int i=pos;i<size;i++){
		List_Array[i]=List_Array[i+1];
	}
	size--;
}

template <class T>
void List_Static<T>::display(ostream &out) const
{
	for(int i=0;i<size;i++)
		out<<List_Array[i]<<" ";
}

template <class T>
ostream& operator << (ostream &out,const List_Static<T> &aList)
{
	aList.display(out);
	return out;
}