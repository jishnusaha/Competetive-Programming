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
 
vector<int> number;
 
ll dp[20][2][2],cnt[20][2][2];
 
ll digit_dp(int pos,int small,int start)
{
    if(dp[pos][small][start]!=-1) return dp[pos][small][start];
 
    int limit=number[pos];
    if(small) limit=9;
 
    if(pos+1==number.size())
    {
        if(start)
        {
            dp[pos][small][1]=1;
            cnt[pos][small][1]=limit+1;
        }
        else
        {
            dp[pos][small][0]=0;
            cnt[pos][small][0]=0;
        }
 
        return dp[pos][small][start];
    }
 
 
    ll ans=0;
    int temp_start=start;
    for(int i=0;i<=limit;i++)
    {
        if(i>0) temp_start=1;
        if(small)
        {
            ans+=digit_dp(pos+1,true,temp_start);
            if(i==0 && start) ans+=cnt[pos+1][true][temp_start];
            cnt[pos][small][start]+=cnt[pos+1][true][temp_start];
 
        }
        else
        {
            if(i<limit)
            {
                ans+=digit_dp(pos+1,true,temp_start);
                if(i==0 && start) ans+=cnt[pos+1][true][temp_start];
                cnt[pos][small][start]+=cnt[pos+1][true][temp_start];
            }
            else
            {
                ans+=digit_dp(pos+1,false,temp_start);
                if(i==0 && start) ans+=cnt[pos+1][false][temp_start];
                cnt[pos][small][start]+=cnt[pos+1][false][temp_start];
            }
        }
    }
    dp[pos][small][start]=ans;
    return dp[pos][small][start];
}
 
 
ll solve(ll a)
{
    if(a==-1) return 0;
    if(a==0) return 1;
    number.clear();
    while(a)
    {
        number.pb(a%10);
        a/=10;
    }
    reverse(number.begin(),number.end());
    mem(dp,-1);
    mem(cnt,0);
    return digit_dp(0,0,0)+1;
}
int main()
{
 
    int t;
    sfi(t);
    tloop(t)
    {
        ll m,n;
        sfll(m,n);
        casenos;
        pfle(solve(n)-solve(m-1));
    }
}
 