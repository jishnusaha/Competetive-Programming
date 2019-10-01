#include<iostream>
using namespace std;
int main()
{
    int T,i,n,r,c;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> n;
        c=0;
        for(;n!=0;)
        {
            if(n%2==1) c++;
            n=n/2;
        }
        if(c%2==0) cout << "Case " << i << ": even\n";
        else cout << "Case " << i << ": odd\n";
    }
}