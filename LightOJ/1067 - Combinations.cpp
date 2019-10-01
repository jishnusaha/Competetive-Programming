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
#define caseno printf("Case %d: ",tlc);
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
#define mx 1000100
int mod=1000003;
long long factorial[mx];
long long big_mod(long long b,long long p,long long m)
{
    if(b==0) return 0;
    if(p==1) return b%m;
    if(p==0) return 1;
    long long r=big_mod(b,p/2,m);
    r*=r;
    r%=m;
    if(p&1) r*=b;
    r%=m;
    return r;
 
}
int main()
{
    int t;
    factorial[0]=1;
    loop(1,mx-1)
    {
        factorial[lc]=factorial[lc-1]*lc;
        factorial[lc]%=mod;
    }
   
    sfi(t);
    tloop(t)
    {
        int n,r;
        sfii(n,r);
        ll denominator=factorial[r]*factorial[n-r];
        denominator%=mod;
 
        ll ans=factorial[n]*big_mod(denominator,mod-2,mod);
        ans%=mod;
        caseno; pfl(ans); nl;
    }
}
 
