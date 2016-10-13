#include "List_Static.cpp"
//using namespace std;
int main()
{
	List_Static<int> alist;
	for(int i=0;i<10;i++){
		alist.insert(i,i/2);
		cout<<alist<<endl;
	}

}