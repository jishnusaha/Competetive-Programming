/*
    idea:
        stars and bar method.
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int lc=i;lc<=n;lc++)
#define tloop(tn) for(int tlc=1;tlc<=tn;tlc++)
#define loop2(i2,n2) for(int lc2=i2;lc2<=n2;lc2++)
#define bloop(n,bn) for(int blc=n;blc>=bn;blc--)
#define il() while(true)
 
 
#define pi acos(-1)
#define rad_to_deg(angl) ((180*angl)/pi)
#define ll long long
#define pb push_back
 
#define pii pair< int,int >
#define pll pair< long long, long long >
#define pib pair< int,bool >
 
#define casenos printf("Case %d: ",tlc);
#define casenonl printf("Case %d:\n",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)
 
#define sfl(def_var) scanf("%lld",&def_var)
#define sfll(def_var,def_var2) scanf("%lld %lld",&def_var,&def_var2)
#define sflll(def_var,def_var2,def_var3) scanf("%lld %lld %lld",&def_var,&def_var2,&def_var3)
 
#define sfd(def_var) scanf("%lf",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfis(def_var) printf("%d ",def_var)
 
#define pfle(def_var) printf("%lld\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfls(def_var) printf("%lld ",def_var)
 
#define pfd(def_var) printf("%lf",def_var)
 
#define nl printf("\n");
 
#define writefile ofstream output; output.open("output.txt");
 
#define limit 2*1000011
#define mod 1000000007
ll fact[limit];
 
ll big_mod(ll b,ll p)
{
    if(b==1) return 1;
    if(b==0) return 0;
    if(p==1) return b%mod;
    if(p==0) return 1;
    ll r=big_mod(b,p/2);
    r*=r;
    r%=mod;
    if(p&1) r*=b;
    r%=mod;
    return r;
}
 
int main()
{
    fact[0]=1;
    for(int i=1;i<limit;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
    int t;
    sfi(t);
    tloop(t)
    {
        int n,k;
        sfii(n,k);
        ll ans=fact[n+k-1];
        ans*=big_mod( (fact[k-1]*fact[n]) % mod,mod-2 );
        ans%=mod;
        casenos;
        pfle(ans);
    }
}
 
