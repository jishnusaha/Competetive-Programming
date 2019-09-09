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
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
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
 
int n,t;
int a[20][20];
bool taken[20];
 
int dp[131100];
int c=0;
int find_ans(int i=1)
{
 
    if(i>n)
    {
        return 0;
    }
    int p=0;
    for(int j=1;j<=n;j++)
    {
        if(taken[j])
        {
            p=p|(1<<(j-1) );
        }
    }
    if(dp[p]>-1)
    {
        return dp[p];
    }
    int ans=-1;
    for(int j=1;j<=n;j++)
    {
 
        if(!taken[j])
        {
            taken[j]=true;
            int temp=find_ans(i+1);
            ans=max(ans,temp+a[i][j]);
            taken[j]=false;
        }
    }
    dp[p]=ans;
    return ans;
}
 
int main()
{
    sfi(t);
    tloop(t)
    {
        sfi(n);
 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                sfi(a[i][j]);
            }
        }
        mem(dp,-1);
        caseno;
        pfie(find_ans(1));
   }
 
 
}
 