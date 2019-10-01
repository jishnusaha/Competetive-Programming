#include<iostream>
using namespace std;
int main()
{
    int T,i;
    long long n,r,p;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> n;
        p=n;
        for(r=0;n!=0;)
        {
            r=r*10;
            r=r+n%10;
            n=n/10;
        }
        cout << "Case " << i << ": ";
        if(r==p) cout << "Yes\n";
        else cout << "No\n";
    }
}