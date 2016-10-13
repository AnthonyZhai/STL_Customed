#include "List_Dynamic.h"
#include <cassert>
using namespace std;
template <class T>
List_Dynamic<T>::List_Dynamic(int maxSize):size(0),capacity(maxSize)
{
	List_Array=new(nothrow) T[maxSize];
	assert(List_Array!=0);
}

template <class T>
List_Dynamic<T>::List_Dynamic(const List_Dynamic<T>& right)
:size(right.size),capacity(right.capacity){
	List_Array=new(nothrow) T[capacity];
	if(List_Array!=0){
		for(int i=0;i<size;i++)
			List_Array[i]=right.List_Array[i];
	}
	else{
		cerr<<"No more mem for creating list!"<<endl;
		exit(1);
	}
}

template<class T>
const List_Dynamic<T>& List_Dynamic<T>::operator =(const List_Dynamic<T>& right)
{
	if(this!=right){
		if(capacity!=right.capacity){
			delete []List_Array;
			capacity=right.capacity;
			List_Array=new(nothrow) T[capacity];
			if(List_Array==0){
				cerr<<"No more mem for creating list!"<<endl;
				exit(1);
			}
		}
		size=right.size;
		for(int i=0;i<size;i++)
			List_Array[i]=right.List_Array[i];
	}
	return *this;
}

template <class T>
List_Dynamic<T>::~List_Dynamic()
{
	delete []List_Array;
	size=0;
	capacity=0;
}

template <class T>
bool List_Dynamic<T>::empty() const
{
	return size==0;
}

template <class T>
void List_Dynamic<T>::insert(T item,int pos)
{
	if(size==capacity){
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
void List_Dynamic<T>::erase(int pos)
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
void List_Dynamic<T>::display(ostream &out) const
{
	for(int i=0;i<size;i++)
		out<<List_Array[i]<<" ";
}

template <class T>
ostream& operator << (ostream &out,const List_Dynamic<T> &aList)
{
	aList.display(out);
	return out;
}