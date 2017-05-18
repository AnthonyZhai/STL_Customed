#include "List_Dynamic.cpp"
int main(){
	List_Dynamic<int > alist;
	for(int i=0;i<10;i++){
		alist.insert(i,i);
		cout<<alist<<endl;
	}
    alist.erase(2);
    alist.insert(100,2);
    cout<<alist;
}