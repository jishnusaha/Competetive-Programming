#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(il,nl) for(int l=il;l<=nl;l++)
#define loop2(il2,nl2) for(int l2=il2;l2<=nl2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
#define tloop(tll,nt) for(int tl=tll;tl<=nt;tl++)
#define caseno printf("Case %d: ",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
 
 
int main()
{
    int t;
    cin >> t;
    tloop(1,t)
    {
        int n,ans=0,i;
        cin >> n;
        int a[n+1];
        a[0]=2;
        loop(1,n) cin >> a[l];
        loop(1,n)
        {
 
            ans+=(a[l]-a[l-1])/5;
            if((a[l]-a[l-1])%5) ans++;
        }
        caseno cout << ans << endl;
    }
}
 
