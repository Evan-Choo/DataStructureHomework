#include <iostream>

using namespace std;

void sort(int&, int&, int&);

int main()
{
    int i, j, k;

    cout << "Enter 3 integers: " << endl;

    cin >> i >> j >> k;

    sort(i, j, k);

    cout << i << " " << j << " " << k << " " << endl;

    return 0;
}

void sort(int &a, int &b, int &c)
{
    if(a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }

    if(b > c)
    {
        int temp = c;
        c = b;
        b = temp;
    }

    if(a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
}