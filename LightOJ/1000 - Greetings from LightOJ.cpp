#include<iostream>
using namespace std;
int main()
{
    int T,a,b,i;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> a >> b;
        cout << "Case " << i << ": " << a+b << endl;
    }
}