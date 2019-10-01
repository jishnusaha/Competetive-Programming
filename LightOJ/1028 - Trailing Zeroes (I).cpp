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
 
 
 
const int p_limit=1010100; 
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
int main()
{
    ///number of divisor will be the ans without 1
    bitwise_sieve();
    int t;
    sfi(t);
    tloop(t)
    {
        ll n;
        sfl(n);
        if(n==1)
        {
            caseno;
            printf("0\n");
            continue;
        }
        ll temp=n;
        int sqrt_n=sqrt(n);
        ll sum=1;
        for(int i=0;i<prime.size() && temp>1 && prime[i]<=sqrt_n;i++)
        {
            int c=0;
            while(temp%prime[i]==0)
            {
                c++;
                temp/=prime[i];
            }
            sum*=c+1;
        }
        if(sum==1 || temp!=1)
        {
            sum*=2;
        }
        caseno;
        printf("%lld\n",sum-1);
    }
}