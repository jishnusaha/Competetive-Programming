/*
    make minimum spanning tree(MST) of the given graph, work on that

    in lca_init we usually keep track 2^i th parent of a node
    now for this problem we will also keep track of maximum edge between a node and its 2^i th parent

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


int n,m;
struct edge{
    int u,v,cost;

    bool operator<(const edge& a) const
    {
        return cost<a.cost;
    }
}edges[100010];

bool cmpr(edge b,edge a)
{
    return b.cost<a.cost;
}

int representative[50010];

///spanning tree adjacency list
vector< pair<int,int> > adj_list[50010];

int find_reperesentative(int x)
{
    if(representative[x]!=x) representative[x]=find_reperesentative( representative[x] );
    return representative[x];
}

bool union_(int x,int y)
{
    int rep_x=find_reperesentative(x);
    int rep_y=find_reperesentative(y);
    if(rep_x==rep_y) return false;

    representative[rep_x]=rep_y;
    return true;
}
void kruskal()
{
    sort(edges,edges+m);
    for(int i=0;i<=n;i++)
    {
        representative[i]=i;
    }
    int e=0;
    for(int i=0;i<m;i++)
    {
        if(union_(edges[i].u,edges[i].v))
        {
            e++;
            adj_list[ edges[i].u ].pb({edges[i].v,edges[i].cost});
            adj_list[ edges[i].v ].pb({edges[i].u,edges[i].cost});
        }
        if(e==n-1) break; ///as minimum spanning tree will have total_node-1 edge
    }
}

int parent[50010][20];
int dangerous_path[50010][20];
bool visited[50010];
int dept[50010];
void dfs(int src,int dept_val=0)
{
    visited[src]=true;
    dept[src]=dept_val;
    for(int i=0;i<adj_list[src].size();i++)
    {
        if(!visited[ adj_list[src][i].first ])
        {
            parent[ adj_list[src][i].first ][0]=src;
            dangerous_path[ adj_list[src][i].first ][0]=adj_list[src][i].second;

            dfs(adj_list[src][i].first,dept_val+1);
        }
    }
}
void lca_init()
{
    int root=1;
    mem(parent,-1);
    mem(dangerous_path,0);
    dfs(root);

    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(parent[i][j-1]!=-1)
            {
                parent[i][j]=parent[ parent[i][j-1]  ][j-1];
                dangerous_path[i][j]=max( dangerous_path[i][j-1], dangerous_path[ parent[i][j-1] ][j-1] );
            }
        }
    }
}

int query(int p,int q) ///this query function is slightly changed from origin lca query
{
    if(dept[p]<dept[q]) swap(p,q);
    int ans=0;
    int log=1;
    while(1)
    {
        if(1<<(log+1)>dept[p]) break;
        log++;
    }
    for(int i=log;i>=0;i--)
    {
        if(dept[p]-(1<<i) >=dept[q])
        {
            ans=max(ans,dangerous_path[p][i]);
            p=parent[p][i];
        }
    }

    if(p==q) return ans;

    for(int i=log;i>=0;i--)
    {
        if(parent[p][i]!=-1 && parent[p][i]!=parent[q][i])
        {
            ans=max(ans,dangerous_path[p][i]);
            ans=max(ans,dangerous_path[q][i]);
            p=parent[p][i];
            q=parent[q][i];
        }
    }

    ans=max(ans,dangerous_path[p][0]);
    ans=max(ans,dangerous_path[q][0]);

    return ans;
}

int main()
{

    int t;
    sfi(t);
    tloop(t)
    {
        sfii(n,m);
        loop(0,m-1) sfiii(edges[lc].u,edges[lc].v,edges[lc].cost);
        kruskal();
        lca_init();
        int q,s,t;
        sfi(q);
        casenonl;
        while(q--)
        {
            sfii(s,t);
            pfie(query(s,t));
        }
        for(int i=0;i<=n;i++)
        {
            adj_list[i].clear();
            visited[i]=false;
        }
    }
}
