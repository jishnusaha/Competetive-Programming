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
 
ll ps[102240];
ll p=0;
ll limit=1e10;
set<ll> myset;
ll fact[102240];
ll mod=1e8+7;
void init()
{
    for(ll i=2;i*i<=limit;i++)
    {
        for(ll j=i*i;j<=limit;j*=i)
        {
            myset.insert(j);
        }
    }
    p=0;
    fact[p]=1;
    for(set<ll> :: iterator it=myset.begin();it!=myset.end();it++)
    {
        ps[p++]=*it;
        fact[p]=fact[p-1]*p;
        fact[p]%=mod;
    }
}
 
 
long long big_mod(long long b,long long p)
{
    ll m=mod;
    if(b==0) return 0;
    if(p==1) return b%m;
    if(p==0) return 1;
    long long r=big_mod(b,p/2);
    r*=r;
    r%=m;
    if(p&1) r*=b;
    r%=m;
    return r;
 
}
int main()
{
    init();
    int t;
    sfi(t);
    tloop(t)
    {
        ll a,b,c;
        sfll(a,b);
        c=upper_bound(ps,ps+p,b)-upper_bound(ps,ps+p,a-1);
        casenos;
        if(!c)
        {
            pfie(0);
            continue;
        }
        ll ans=fact[2*c];
        ans*=big_mod(fact[c],mod-2);
        ans%=mod;
        ans*=big_mod(fact[c+1],mod-2);
        ans%=mod;
        pfle(ans);
    }
}