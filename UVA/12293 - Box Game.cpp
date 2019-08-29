#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>> n)
    {
        if(n==0) break;
        if( (n&(n+1) )==0) cout << "Bob\n";
        else cout << "Alice\n";
    }
}