#include <iostream>

using namespace std;

int main()
{
	char c = '6';
	const int &rc=c;
	int i=8;
	const int &ri=i;

	cout << &c << endl;
	cout << &rc << endl;
	cout << &i << endl;
	cout << &ri << endl;
	
	cout << ((int *)&c==&rc) << endl;
	cout << (&i==&ri) << endl;
	

	return 0;
}