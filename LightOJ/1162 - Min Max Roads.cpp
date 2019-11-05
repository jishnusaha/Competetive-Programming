/*

    in lca_init we usually keep track 2^i th parent of a node
    now for this problem we will also keep track of
        maximum weighted edge between a node and its 2^i th parent
        minimum weighted edge between a node and its 2^i th parent

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

vector< pair<int,int> > adj_list[100100];
bool visited[100100];
int dept[100100];
int parent[100100][18];
int mini[100100][18];
int maxi[100100][18];
int n;
void dfs(int src,int dept_val=0)
{
    visited[src]=true;
    dept[src]=dept_val;
    for(int i=0;i<adj_list[src].size();i++)
    {
        if(!visited[ adj_list[src][i].first ])
        {
            parent[ adj_list[src][i].first ][0]=src;
            mini[ adj_list[src][i].first ][0]=adj_list[src][i].second;
            maxi[ adj_list[src][i].first ][0]=adj_list[src][i].second;
            dfs(adj_list[src][i].first,dept_val+1);
        }
    }
}

void init_lca()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<18;j++)
        {
            parent[i][j]=-1;
            mini[i][j]=INT_MAX;
            maxi[i][j]=0;
        }
    }
    dfs(1);
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(parent[i][j-1]!=-1)
            {
                parent[i][j]=parent[ parent[i][j-1] ][j-1];
                mini[i][j]=min( mini[i][j-1],mini[ parent[i][j-1] ][j-1] );
                maxi[i][j]=max( maxi[i][j-1],maxi[ parent[i][j-1] ][j-1] );
            }
        }
    }
}
pair<int,int> lca_query(int p,int q)
{
    pair<int,int>ret;
    ret={0,INT_MAX};
    if(dept[p]<dept[q]) swap(p,q);

    int log=log2( dept[p] )+1;

    for(int i=log;i>=0;i--)
    {
        if(dept[p]-(1<<i) >=dept[q] )
        {
            ret.first=max(ret.first,maxi[p][i]);
            ret.second=min(ret.second,mini[p][i]);
            p=parent[p][i];
        }
    }
    if(p==q)
    {
        return ret;
    }
    for(int i=log;i>=0;i--)
    {
        if(parent[p][i]!=-1 && parent[p][i]!=parent[q][i])
        {
            ret.first=max(ret.first,maxi[p][i]);
            ret.second=min(ret.second,mini[p][i]);
            ret.first=max(ret.first,maxi[q][i]);
            ret.second=min(ret.second,mini[q][i]);
            p=parent[p][i];
            q=parent[q][i];
        }
    }
    ret.first=max(ret.first,maxi[p][0]);
    ret.second=min(ret.second,mini[p][0]);
    ret.first=max(ret.first,maxi[q][0]);
    ret.second=min(ret.second,mini[q][0]);

    return ret;

}

int main()
{

    int t;
    sfi(t);
    tloop(t)
    {
        sfi(n);
        int u,v,w;
        loop(1,n-1)
        {
            sfiii(u,v,w);
            adj_list[u].pb({v,w});
            adj_list[v].pb({u,w});
        }
        init_lca();

        int q,x,y;
        sfi(q);
        casenonl;
        pair<int,int>ans;
        while(q--)
        {
            sfii(x,y);
            ans=lca_query(x,y);
            pfis(ans.second);
            pfie(ans.first);
        }
        loop(0,n)
        {
            adj_list[lc].clear();
            visited[lc]=false;
        }
    }
}
