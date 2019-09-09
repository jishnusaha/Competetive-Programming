#include <bits/stdc++.h>
 
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
 
 
int a[60],c[60],taken[60];
int n,k;
int dp[51][1001][21];
int mod=100000007;
 
int solve(int i,int amount)
{
    if(i==n+1)
    {
        if(amount==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
 
    }
    if(dp[i][amount][c[i]]!=-1)
    {
        return dp[i][amount][c[i]];
    }
    int res1=0,res2=0;
    if(c[i]>0 && amount-a[i]>=0)
    {
        c[i]--;
        res1=solve(i,amount-a[i]);
        c[i]++;
    }
    res2=solve(i+1,amount);
    res1+=res2;
    res1%=mod;
    dp[i][amount][c[i]]=res1;
    return dp[i][amount][c[i]];
 
}
int main()
{
    int t;
    cin >> t;
    tloop(t)
    {
        cin >> n >> k;
 
        for(int i=0;i<51;i++)
        {
            taken[i]=0;
            for(int j=0;j<1001;j++)
            {
                for(int p=0;p<21;p++)
                {
                    dp[i][j][p]=-1;
 
                }
            }
        }
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> c[i];
        caseno; printf("%d\n",solve(1,k));
 
    }
}
 