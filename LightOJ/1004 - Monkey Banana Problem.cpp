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
 
vector<ll>v[100*2-1];
vector<ll>dp[100*2-1];
ll n;

ll get_solution(int r,int c)
{
    if(dp[r][c]>0) return dp[r][c];
    if(r==n*2-1 -1)
    {
        dp[r][c]=v[r][c];
        return dp[r][c];
    }
    if(r<n-1)
    {
        dp[r][c]=v[r][c]+max( get_solution(r+1,c), get_solution(r+1,c+1));
    }
    else
    {
        int res1=0,res2=0;
        if(c>0) res1=get_solution(r+1,c-1);
        if(v[r+1].size()>c) res2=get_solution(r+1,c);
        dp[r][c]=v[r][c]+max(res1,res2);
    }
    return dp[r][c];
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        ll p;
        sfl(n);
 
        int limit=0;
        loop(0,n*2-1-1)
        {
 
            if(lc<n) limit++;
            else limit--;
            for(int i=0;i<limit;i++)
            {
                sfl(p);
                v[lc].push_back(p);
                dp[lc].push_back(-1);
            }
        }
        caseno; printf("%lld\n",get_solution(0,0));
        for(int i=0;i<2*n-1;i++)
        {
            v[i].clear();
            dp[i].clear();
        }
    }
 
 
}