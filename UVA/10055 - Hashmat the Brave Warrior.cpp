#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    long long a,b;
    while(cin >> a >>b)
    {
        if(b>a) cout << b-a << endl;
        else cout << a-b << endl;
    }
}