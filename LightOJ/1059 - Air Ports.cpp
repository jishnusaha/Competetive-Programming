/*
    target is to minimize the total implementation cost;
    if multiple solution found try to find build maximum airport
 
    cost will be minimize if we build a MST from that given graph
    then if there are multiple tree found,
        for every tree
            we will split the tree into multiple tree removing the edges
            which cost is >= airport_building_cost
        then for every ultimate existing tree, we will build an airport for each tree
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
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfis(def_var) printf("%d ",def_var)
 
#define pfle(def_var) printf("%lld\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfls(def_var) printf("%lld ",def_var)
 
#define pfd(def_var) printf("%lf",def_var)
 
#define nl printf("\n");
 
#define mx_node 10001
#define mx_edge 100001
struct e{
    int u,v,cost;
 
}edges[mx_edge];
bool cmpr(e b, e a)
{
    return b.cost<a.cost;
}
 
int total_edge,total_node,airport_cost;
 
struct node{
    int vartex,cost;
};
vector< node >spanning_tree[mx_node];
 
struct s{
    int parent,rank_;
}subset[mx_node];
 
int find_root(int x)
{
    if(subset[x].parent!=x)
    {
        subset[x].parent=find_root(subset[x].parent);
    }
    return subset[x].parent;
}
bool union_(int p,int q)
{
    int proot=find_root(p);
    int qroot=find_root(q);
 
    if(proot==qroot) return false;
 
    if(subset[proot].rank_>subset[qroot].rank_) subset[qroot].parent=proot;
    if(subset[proot].rank_<subset[qroot].rank_) subset[proot].parent=qroot;
 
    if(subset[proot].rank_==subset[qroot].rank_)
    {
        subset[qroot].parent=proot;
        subset[proot].rank_++;
    }
 
    return true;
}
 
void kruskal()
{
    sort(edges,edges+total_edge,cmpr);
 
    for(int i=0;i<=total_node;i++)
    {
        subset[i].parent=i;
        subset[i].rank_=0;
    }
 
    for(int i=0;i<total_edge;i++)
    {
        if(union_(edges[i].u,edges[i].v) && edges[i].cost<airport_cost) ///if union possible && no cycle
        {
            spanning_tree[ edges[i].u ].pb( {edges[i].v,edges[i].cost  } );
            spanning_tree[ edges[i].v ].pb( {edges[i].u,edges[i].cost  } );
        }
    }
}
bool pushed[mx_node];
ll bfs(int src)
{
    ll cost=0;
    pushed[src]=true;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<spanning_tree[u].size();i++)
        {
            int v=spanning_tree[u][i].vartex;
            if(!pushed[v])
            {
                pushed[v]=true;
                q.push(v);
                cost+=spanning_tree[u][i].cost;
            }
        }
    }
    return cost;
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        sfiii(total_node,total_edge,airport_cost);
        for(int i=0; i<total_edge;i++)
        {
            sfiii(edges[i].u,edges[i].v,edges[i].cost);
        }
        kruskal();
 
        ll ans=0,airport=0;
 
 
        loop(1,total_node)
        {
            if(!pushed[lc])
            {
                ans+=bfs(lc)+airport_cost;
                airport++;
            }
        }
        loop(1,total_node)
        {
            pushed[lc]=false;
            spanning_tree[lc].clear();
        }
        casenos;
        pfls(ans);
        pfle(airport);
 
    }
}
 