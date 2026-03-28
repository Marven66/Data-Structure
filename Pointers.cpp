#include <iostream>
using namespace std;
int main()
{
	int x;
	int &y = x;
	cout << &x << endl;
	cout << &y << endl;

	int *z = &y;
	cout << z << endl;
	cout << &z << endl;


	int *p = new int;
	delete p;

	return 0;
}