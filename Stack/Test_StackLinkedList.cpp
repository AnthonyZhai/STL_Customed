#include "Stack_LinkedList.cpp"
#include <iostream>
using namespace std;
int main()
{
	Stack_LinkedList<int> alist;
	alist.push(100);
	alist.push(2);
	alist.push(33);
	alist.pop();
	alist.pop();
	cout<<alist<<endl;
	cout<<alist.getTop()<<endl;
	cout<<alist.getSize()<<endl;
}