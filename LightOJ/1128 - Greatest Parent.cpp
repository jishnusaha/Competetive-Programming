/*

    LCA problem

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

#define casenownl output << "Case " << tlc << ":\n";
#define casenows output << "Case " << tlc << ": ";

#define READ        freopen("input.txt","r",stdin)
#define WRITE       freopen("output.txt","w",stdout)
#define BOOST       ios_base::sync_with_stdio(false);cin.tie(NULL)

int value[100010];

vector<int>adj_list[100010];
int parent[100010][18];
int n;

void init()
{
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;i<=n;i++)
        {
            if(parent[i][j-1]!=-1)
            {
                parent[i][j]=parent[ parent[i][j-1] ][ j-1 ];
            }

        }
    }
}

int query(int k,int v)
{
    int i=16;
    bool jumped=false;
    while(i>=0)
    {
        if(parent[k][i]!=-1 && value[ parent[k][i] ]>=v )
        {
            k=parent[k][i];
        }
        i--;
    }
    return k;
}
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int q;
        sfii(n,q);
        value[0]=1;
        mem(parent[0],-1);
        int p,s;
        loop(1,n-1)
        {
            mem(parent[lc],-1);
            sfii(p,s);
            value[lc]=s;
            parent[lc][0]=p;
        }
        init();
        int k,v;
        casenonl;
        while(q--)
        {
            sfii(k,v);
            pfie(query(k,v));
        }
    }
}
