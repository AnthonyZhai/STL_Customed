#include "Stack_Dynamic.cpp"
int main()
{
	Stack_Dynamic<int> a;
	a.push(2);
	a.push(3);
	a.push(-1);
	cout<<a<<endl;
	Stack_Dynamic<int> b(a);
	Stack_Dynamic<int> c=a;
	a.pop();
	cout<<a.getTop()<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;

}