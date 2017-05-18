#include "LinkedList.cpp"
int main()
{
	LinkedList<int> Alist;
	for(int i=1;i<10;i++){
		Alist.push(i);
		cout<<Alist<<endl;
	}
	for(int i=1;i<10;i++){
		Alist.pop();
		cout<<Alist<<endl;
	}

		
}