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
 
 
const int p_limit=101; 
int status[p_limit+1];
int factors[110][110];
 
void factorization_sieve()
{
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
 
int current_n=0;
void prime_factorization(long long n)
{
    if(n==0 || n==1) return ;
 
    int largest_prime=status[n];
    if(largest_prime==0) largest_prime=2;
    int c=0;
    while(n%largest_prime==0)
    {
        c++;
        n/=largest_prime;
    }
    factors[current_n][largest_prime]=c;
    if(!(n==0 || n==1))
    {
        prime_factorization(n);
    }
    return ;
}
 
void init()
{
    for(current_n=2;current_n<=100;current_n++)
    {
        prime_factorization(current_n);
        for(int p=0;p<=100;p++)
        {
            if(factors[current_n-1][p]) factors[current_n][p]+=factors[current_n-1][p];
        }
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
        int n;
        sfi(n);
        caseno;
        printf("%d = ",n);
        int i;
        for(i=1;i<=100;i++)
        {
            if(factors[n][i])
            {
                printf("%d (%d)",i,factors[n][i]);
                break;
            }
 
        }
        for(i++;i<=100;i++)
        {
            if(factors[n][i])
            {
                printf(" * %d (%d)",i,factors[n][i]);
            }
        }
        nl;
    }
}
 