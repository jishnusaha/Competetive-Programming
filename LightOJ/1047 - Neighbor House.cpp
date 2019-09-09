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
#define sfll(def_var,def_var2) scanf("%lld %lld",&def_var,&def_var2)
 
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
int n;
int dp[22][3],a[22][3];

void find_solution(int curr,int p)
{
    if(dp[p][curr]!=-1) return ;
 
    if(p==n-1)
    {
        dp[p][0]=a[p][0];
        dp[p][1]=a[p][1];
        dp[p][2]=a[p][2];
        return;
    }
    int ans1,ans2;
    if(curr==0)
    {
        find_solution(1,p+1);
        find_solution(2,p+1);
        dp[p][curr]=min( dp[p+1][1] , dp[p+1][2] ) + a[p][curr];
 
    }
    if(curr==1)
    {
        find_solution(0,p+1);
        find_solution(2,p+1);
        dp[p][curr]=min( dp[p+1][0] , dp[p+1][2] ) + a[p][curr];
 
    }
    if(curr==2)
    {
        find_solution(1,p+1);
        find_solution(0,p+1);
        dp[p][curr]=min( dp[p+1][1] , dp[p+1][0] ) + a[p][curr];
 
    }
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        sfi(n);
        loop(0,n-1)
        {
            sfii(a[lc][0],a[lc][1]);
            sfi(a[lc][2]);
        }
        loop(0,n-1)
        {
            dp[lc][0]=dp[lc][1]=dp[lc][2]=-1;
        }
        find_solution(0,0);
        find_solution(1,0);
        find_solution(2,0);
        caseno;
        if(dp[0][0]<dp[0][1] && dp[0][0]<dp[0][2]) printf("%d\n",dp[0][0]);
        else if(dp[0][1]<dp[0][2]) printf("%d\n",dp[0][1]);
        else printf("%d\n",dp[0][2]);
    }
 
}