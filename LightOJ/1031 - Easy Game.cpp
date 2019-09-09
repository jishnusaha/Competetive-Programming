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
 
int dp[110][110][2];
int n;
int a[110];
int sum(int l,int r)
{
    int s=0;
    loop(l,r) s+=a[lc];
    return s;
}
 
int find_ans(int l,int r,bool a_move)
{
    if(l>r)
    {
        return 0;
 
    }
    if(a_move)
    {
        if(dp[l][r][0]!=INT_MIN)
        {
            return dp[l][r][0];
        }
        for(int i=l;i<=r;i++)
        {
 
            int temp;
            if(dp[i+1][r][1]!=INT_MAX) temp=dp[i+1][r][1];
            else
            {
                temp=find_ans(i+1,r,!a_move);
            }
            int p=sum(l,i)+temp;
            dp[l][r][0]=max(dp[l][r][0],p);
        }
        for(int i=r;i>=l;i--)
        {
            int temp;
            if(dp[l][i-1][1]!=INT_MAX) temp=dp[l][i-1][1];
            else
            {
                temp=find_ans(l,i-1,!a_move);
            }
            int p=sum(i,r)+temp;
            dp[l][r][0]=max(dp[l][r][0],p);
        }
        return dp[l][r][0];
    }
    else
    {
        if(dp[l][r][1]!=INT_MAX)
        {
            return dp[l][r][1];
        }
 
        for(int i=l;i<=r;i++)
        {
            int temp;
            if(dp[i+1][r][0]!=INT_MIN) temp=dp[i+1][r][0];
            else
            {
                temp=find_ans(i+1,r,!a_move);
            }
            int p=temp-sum(l,i);
            dp[l][r][1]=min(dp[l][r][1],p);
        }
        for(int i=r;i>=l;i--)
        {
            int temp;
            if(dp[l][i-1][0]!=INT_MIN) temp=dp[l][i-1][0];
            else
            {
                temp=find_ans(l,i-1,!a_move);
            }
            int p=temp-sum(i,r);
            dp[l][r][1]=min(dp[l][r][1],p);
        }
        return dp[l][r][1];
    }
 
}
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        sfi(n);
        loop(0,n-1) sfi(a[lc]);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j][0]=INT_MIN;
                dp[i][j][1]=INT_MAX;
            }
        }
        caseno;
        pfie(find_ans(0,n-1,true));
    }
}
 