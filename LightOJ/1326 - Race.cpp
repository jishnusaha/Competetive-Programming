/*
    idea:
        for input 3:
            provable solution:
                all 3 horses first (3c3)
                2 first 1 second (3c2 * 1c1)
                1 first 2 second (3c1 * 2c2)
                1 first 1 second 1 third. (3c1 * 2c1 * 1c1)
                ans : (3c3) + (3c2 * 1c1) + (3c1 * 2c2) + (3c1 * 2c1 * 1c1)
       
        for input 4:
            provable solution:
                all 4 horses first (4c4)
                3 first 1 second (3c3 * 1c1)
                2 first 2 second (2c2 * 2c2)
                2 first 1 second 1 third (4c2 * 2c1 * 2c1)
                1 first 3 second (4c1 * 3c3)
                1 first 2 second 1 third (4c1 * 3c2 * 1c1)
                1 first 1 second 2 third (4c1 * 3c1 * 2c2)
                1 first 1 second 1 third 1 fourth (4c1 * 3c1 * 2c1 * 1c1)
                ans :  (4c4) + (3c3 * 1c1) +(2c2 * 2c2) + (4c2 * 2c1 * 2c1) + (4c1 * 3c3) + (4c1 * 3c2 * 1c1) + (4c1 * 3c1 * 2c2) + (4c1 * 3c1 * 2c1 * 1c1)
       
        NB: maximum position will be total horse count.
            horses will take position in particular position if previous one is taken by at least one horse
            ex: for input 4, 2 first, 0 second 2 third not possible. just commonsense
       
        if we write those combination line by line we will get the redundant calculations. optimize by memorization
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
 
int ncr[1010][1010];
int mod=10056;
int total_horse;
int calculate_ncr(int n,int r)
{
    if(ncr[n][r]!=-1) return ncr[n][r];
 
    if(n<r) return 0;
    if(r==1) ncr[n][r]=n;
    else if(r==0) ncr[n][r]=1;
    else ncr[n][r]=calculate_ncr(n-1,r)+calculate_ncr(n-1,r-1);
    ncr[n][r]%=mod;
    return ncr[n][r];
}
 
int dp[1010][1010];
 
ll cnt(int n,int  pos)
{
    if(n==0) return 1;
    if(pos==total_horse) return 1;
 
    if(dp[n][n]!=-1) return dp[n][n];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=ncr[n][n-i]*cnt(i,pos+1);
        ans%=mod;
    }
    dp[n][n]=ans;
    return ans;
}
int solve()
{
    if(dp[total_horse][total_horse]!=-1) return dp[total_horse][total_horse];
    int ans=0;
    for(int i=0;i<total_horse;i++)
    {
        ans+=cnt(i,2)*ncr[total_horse][total_horse-i];
        ans%=mod;
    }
    dp[total_horse][total_horse]=ans;
    return ans;
}
void generate_ncr()
{
    mem(ncr,-1);
    for(int n=1000;n>=0;n--)
    {
        for(int r=n;r>=0;r--)
        {
            if(ncr[n][r]==-1) calculate_ncr(n,r);
        }
    }
}
int main()
{
    generate_ncr();
 
    int t,n;
    sfi(t);
    mem(dp,-1);
    tloop(t)
    {
        sfi(total_horse);
        casenos;
        pfie(solve());
    }
}
 