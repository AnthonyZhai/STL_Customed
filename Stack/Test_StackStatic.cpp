#include "Stack_Static.cpp"
int main()
{
	Stack_Static<int> SS;
	SS.push(1);
	SS.push(2);
	SS.push(288);
	SS.push(100);
	cout<<SS<<endl;
	cout<<SS.getTop()<<endl;

	SS.pop();
	SS.pop();
	SS.pop();
	SS.pop();
	cout<<SS.getTop()<<endl;
}