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
 
 
const int p_limit=1100; 
int status[p_limit+1];
pair<int,int> data[1010];
 
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
int divisor=1;
void count_divisor(long long n)
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
    divisor*=(c+1);
    if(!(n==0 || n==1))
    {
        count_divisor(n);
    }
    return ;
}
void init()
{
    data[1].first=1;
    data[1].second=-1;
 
    for(int n=2;n<=1000;n++)
    {
        divisor=1;
        data[n].second=-n;
        count_divisor(n);
        data[n].first=divisor;
    }
    sort(data+1,data+1001);
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
        caseno; printf("%d\n",-data[n].second);
    }
}
 
