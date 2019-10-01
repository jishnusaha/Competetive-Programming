#include<iostream>
using namespace std;
int main()
{
    int T,n,a,b;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> n;
        if(n>=10) {a=n-10; b=n-a;}
        else {b=n; a=n-b;}
        cout << a << " " << b << endl;
    }
}