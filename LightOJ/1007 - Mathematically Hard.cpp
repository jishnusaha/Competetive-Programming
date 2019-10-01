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
 
const int p_limit=5000100; 
int status[p_limit+1];
unsigned ll scores[p_limit];

void factorization_sieve()
{
//    note:
//    this function  store in status array by the largest prime factor of a number
//    largest prime factor of 60 is 5 then, status[60] will contain 5
//    if a number is 2^n then largest prime factor of it is 2. but it is not stored.
//    so if you get a even number p and status[p]==0 then it's largest prime factor will be 2
 
    int i;
    for(i=3;i<p_limit/2;i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i;j<=p_limit;j+=i)
            {
                status[j]=i;
            }
        }
    }
    for(;i<=p_limit;i+=2)
    {
        if(status[i]==0)
        {
            status[i]=i;
        }
    }
 
}
 
unsigned ll up=1,down=1;
void count_score(long long n)
{
    if(n==0 || n==1) return ;
 
    int largest_prime=status[n];
    if(largest_prime==0) largest_prime=2;
    int c=0;
    while(n%largest_prime==0)
    {
        n/=largest_prime;
    }
 
    up*=largest_prime-1;
    down*=largest_prime;
 
    if(!(n==0 || n==1))
    {
        count_score(n);
    }
    return ;
}
 
void init()
{
    scores[1]=0;
    for(int n=2;n<p_limit;n++)
    {
        up=1,down=1;
        count_score(n);
        unsigned ll scoreN=up*(n/down);
        scoreN*=scoreN;
 
        scores[n]+=scoreN+scores[n-1];
    }
}
int main()
{
    factorization_sieve();
    init();
    int t;
    sfi(t);
    tloop(t)
    {
        int a,b;
        sfii(a,b);
        caseno; printf("%llu\n",scores[b]-scores[a-1]);
    }
}
 
 
 
 
