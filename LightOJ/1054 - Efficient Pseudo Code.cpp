/*
	number of divisor will be the ans without 1
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
 
 
 
const int p_limit=1000100; ///comment out const and say the limit error will be out
long long mod=1000000007;
int status[(p_limit/32)+1];
 
vector<int>prime;
void setstatus(int &n,int pos)
{
    n|=(1<<pos);
}
 
int check_status(int n,int pos)
{
    return n=n&(1<<pos);
}
 
void bitwise_sieve()
{
    prime.push_back(2);
    int c,i;
    int sqrtn=sqrt(p_limit);
    for(i=3;i<=sqrtn;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            prime.push_back(i);
            for(int j=i*i;j<=p_limit;j+=2*i)
            {
                setstatus(status[j>>5],j&31);
            }
        }
    }
    setstatus(status[0],1);
    for(;i<=p_limit;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            prime.push_back(i);
        }
    }
}
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
    bitwise_sieve();
    int t;
    sfi(t);
    tloop(t)
    {
        int n,m;
        sfii(n,m);
        int temp=n;
        int sqrt_n=sqrt(temp);
        vector< pair<int,long long> >prime_factor;
        for(int i=0;i<prime.size() && prime[i]<=sqrt_n && temp>1;i++)
        {
 
            ll c=0;
            while(temp%prime[i]==0)
            {
                c++;
                temp/=prime[i];
            }
            c*=m;
            if(c) prime_factor.push_back(make_pair(prime[i],c ));
        }
        if(temp>1)
        {
            prime_factor.push_back(make_pair(temp,m) );
        }
        long long ans=1;
 
        for(int i=0;i<prime_factor.size();i++)
        {
            ///(((p1^(m*k1+1) )-1 )/(p1-1) )%mod
            ///( (p1^(m*k1+1) )%m - 1%mod) *( ((p1-1)^(mod-2))%mod )
 
            ll p=prime_factor[i].first;
            ll k=prime_factor[i].second;
            ///first (p1^(m*k1+1) )%mod
            ll value=big_mod(p,k+1,mod);
 
            ///second 1%mod
            value-=1;
            if(value<0) value+=mod;  ///negative value correction
            value%=mod;
            ans*=value;
            ans%=mod;
 
            ///last ((p1-1)^(m-2))%mod
            ans*=big_mod(p-1,mod-2,mod);
            ans%=mod;
        }
        caseno; pfl(ans); nl;
 
    }
}
