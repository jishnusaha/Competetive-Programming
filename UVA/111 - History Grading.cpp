/*
    lcs

    here, the given sequence is denoting the position of the a number.
    ex: if a given sequence is 4 2 1 3
        then, then actual serial of the evens is 3 2 4 1

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

#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
#define BOOST		ios_base::sync_with_stdio(false);cin.tie(NULL)


int c[30],r[30];
int n;
int dp[30][30];

int lcs(int i=0,int j=0)
{
    if(i==n || j==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(c[i]==r[j]) dp[i][j]=1+lcs(i+1,j+1);
    else dp[i][j]=max(lcs(i+1,j),lcs(i,j+1));
    return dp[i][j];
}
int main()
{
    sfi(n);
    int p;
    loop(0,n-1)
    {
        sfi(p);
        c[p-1]=lc; //p-1 because we are using 0 base indexing
    }
    while(cin >> p)
    {
        r[p-1]=0;
        loop(1,n-1)
        {
            sfi(p);
            r[p-1]=lc;
        }
        mem(dp,-1);
        pfie(lcs());
    }
}
