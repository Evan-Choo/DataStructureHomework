#include <iostream>
using namespace std;

int main()
{
    int n, r;

    cout << "Enter 2 integers n and r: " << endl;
    cin >> n >> r;

    int people[n];

    //assign every people a number form 1 to n
    for(int i = 0; i < n; i++)
    {
        people[i] = i+1;
    }

    int j = 0;			//when j == r, print out the current number
    int counter = 0;	//when counter == 10, break the loop
    for(int i = 0;;i++)
    {
        int k = i%n;    //k ranges from 0 to n-1

        if(people[k] != 0)
        {
            j++;		//only when the current number isn't 0 can j plus one
            if(j == r)
            {
                cout << people[k] << endl;
                counter++;
                people[k] = 0; //the people is out
                j = 0;
            }
        }

        if(counter == n)
            break;
    }

    return 0;
}