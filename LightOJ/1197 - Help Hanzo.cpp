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
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
 
 
 
const int p_limit=46400; 
int status[ (p_limit/32)+ 1 ];
 
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
const int segment_range=101010;
int segment_primes_status[segment_range];
 
void segment_sieve(long long low,long long high)
{
//    bitwise_sieve must be called in main before call this function
//    this function will store prime status in segment_primes_status by bits
//    assign segment range value as given
    //** even numbers should be checked
 
 
    for(int i=0;i<segment_range;i++) segment_primes_status[i]=0;
 
    int range=high-low+1;
    int sqrt_high=sqrt(high);
 
    for(int p=1;prime[p]<=sqrt_high && p<prime.size();p++)
    {
        ///computing the first value in range [low,high] divisible by prime[p]
        long long i=low/prime[p];
        i*=prime[p];
        if(i<low) i+=prime[p];
        if(i==prime[p]) i+=prime[p];
        if(!(i&1)) i+=prime[p];
        for(;i<=high;i+=2*prime[p])
        {
            segment_primes_status[i-low]=1;
        }
    }
    if(low==1) segment_primes_status[0]=1;
 
}
int main()
{
    bitwise_sieve();
    int t;
    sfi(t);
    tloop(t)
    {
        int a,b;
        sfii(a,b);
        int low=a;
        int c=0;
        segment_sieve(a,b);
        if(a==2)
        {
            a++; c++;
        }
        if(a==1 && b>1)
        {
            a=3;
            c++;
        }
        if(a%2==0) a++;
        for(ll i=a;i<=b;i+=2)
        {
            if(segment_primes_status[i-low]==0)
            {
                c++;
            }
        }
        caseno; pfie(c);
    }
}
 
