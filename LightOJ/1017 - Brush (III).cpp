/*
approach:
        normal napsack type approach.
        if we don't take we move to the next position.
        if we take, then we move to the position where new_position=current_position+range we can take by w+1
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
 
int n,w,k;
int pos[101];
 
int dp[101][101];
 
int find_ans(int p=0,int mv=0)
{
    if(mv==k || p==n) return 0;
    if(dp[p][mv]>-1) return dp[p][mv];
    int dust1=find_ans(p+1,mv);
    int low=pos[p];
    int high=low+w;
 
    int upper_limit=upper_bound(pos,pos+n,high)-pos-1;
    int dust2=upper_limit-p+1+find_ans(upper_limit+1,mv+1);
    dp[p][mv]= max(dust1,dust2);
    return dp[p][mv];
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int p;
        sfii(n,w); sfi(k);
        for(int i=0;i<n;i++)
        {
            sfii(p,pos[i]);
        }
        sort(pos,pos+n);
        mem(dp,-1);
        caseno; pfie(find_ans());
    }
}
 