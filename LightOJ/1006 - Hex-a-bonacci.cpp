#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define il() while(1)
#define pi acos(-1)
#define ll long long
 
ll a, b, c, d, e, f;
ll ans[10002];

ll fn( ll n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(ans[n]!=-1) { return ans[n]; }
    ans[n]=(fn(n-1)+fn(n-2)+fn(n-3)+fn(n-4)+fn(n-5)+fn(n-6))%10000007;
    return ans[n];
}
int main() {
    ll n, caseno = 0, cases;
    scanf("%ld", &cases);
    for(int i=1;i<=cases;i++)
    {
        cin >> a >> b >> c >> d >> e >> f >> n;
        loop(0,n) ans[l]=-1;
        ans[0]=a;
        ans[1]=b;
        ans[2]=c;
        ans[3]=d;
        ans[4]=e;
        ans[5]=f;
        cout << "Case " << i << ": " << fn(n) % 10000007 << endl;;
    }
    return 0;
}
 
