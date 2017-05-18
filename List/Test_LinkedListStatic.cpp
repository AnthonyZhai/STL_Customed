#include "LinkedList_Static.cpp"

int main(){
	LinkedList_Static<int> a;
	a.newNode(1);
	a.newNode(2);
	a.newNode(12);
	a.newNode(200);

	a.deleteNode(2);
	a.deleteNode(0);
	cout<<a<<endl;
}