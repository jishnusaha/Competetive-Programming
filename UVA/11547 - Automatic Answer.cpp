#include <iostream>
#include<cmath>
using namespace std;
int main()
{

    int t;
    long long n;
    cin >>t;
    while(t--)
    {
        cin >>n;
        n=((((n*567)/9+7492)*235)/47)-498;
        n=n/10;
        n=n%10;
        cout << abs(n) <<endl;
    }
}