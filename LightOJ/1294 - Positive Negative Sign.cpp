#include<iostream>
using namespace std;
int main()
{
    int n;
 
    int T,p,i,j;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        long long n,m;
        cin >> n >> m;
        long long ans=m*m;
        ans*=n/(m*2);
 
        cout << "Case " << i << ": " << ans << endl;
 
    }
}