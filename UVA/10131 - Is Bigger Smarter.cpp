/*
    lcs problem.
    sort according to weight in asc
            then, desc of iq
    select the best lcs
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

#define casenos printf("Case #%d: ",tlc);
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

#define casenownl output << "Case " << tlc << ":\n";
#define casenows output << "Case " << tlc << ": ";

#define debug cout

#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
#define BOOST		ios_base::sync_with_stdio(false);cin.tie(NULL)


struct data{
    int w,iq,sl;

    bool operator<(const data& a)const
    {
        if(w < a.w) return true;
        else if (w > a.w) return false;
        else return a.iq>iq;
    }

}el[1005];
int n=0;

int dp[1005][1005][2];
int taken[1001];
int mx_found=-1;
int lcs(int curr=1,int prev=0,int t=0)
{
    if(curr>=n)
    {
        return 0;
    }
    if(dp[curr][prev][0]!=-1 && dp[curr][prev][1]!=-1)
	{
        return max(dp[curr][prev][1],dp[curr][prev][0]);
	}
    if(t==0)
    {
        taken[t]=curr;
        dp[curr][prev][1]=1+lcs(curr+1,curr,t+1);
        dp[curr][prev][0]=lcs(curr+1,prev,t);
        mx_found=max(dp[curr][prev][0],dp[curr][prev][1]);
        return mx_found;
    }
    else
    {
        if( el[prev].w< el[curr].w && el[prev].iq>el[curr].iq )
        {
            taken[t]=curr;
            dp[curr][prev][1]=1+lcs(curr+1,curr,t+1);
        }
        dp[curr][prev][0]=lcs(curr+1,prev,t);
        return max( dp[curr][prev][0],dp[curr][prev][1]);
    }
}

int main()
{
    int w,iq;
	n=1;
    while(cin >> w >> iq)
    {
        el[n].w=w;
        el[n].iq=iq;
        el[n].sl=n; n++;
    }
    sort(el+1,el+n);
    mem(dp,-1);
    lcs();
    pfie(mx_found);
    int prev=0;
    for(int i=1;mx_found>0;i++)
    {
        if(dp[i][0][1]==mx_found && ( prev==0 || el[prev].w< el[i].w && el[prev].iq>el[i].iq  ) )
        {
            prev=i;
            pfie(el[i].sl);
            mx_found--;
        }
    }
}
