/*
    make spanning tree call dfs from given city.
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
 
#define mx_node 501
#define mx_edge 16001
 
 
int total_edge,total_node;
struct e{
    int u,v,cost;
}edges[mx_edge];
 
bool cmpr(e b,e a)
{
    return b.cost<a.cost;
}
struct s{
    int parent,rank_;
}subset[mx_node];
 
int find_(int x)
{
    if(subset[x].parent!=x) subset[x].parent=find_(subset[x].parent);
    return subset[x].parent;
}
 
bool union_(int p,int q)
{
    int proot=find_(p);
    int qroot=find_(q);
 
    if(proot==qroot) return false; ///this will create cycle
 
    if(subset[proot].rank_<subset[qroot].rank_) subset[proot].parent=qroot;
    else if(subset[proot].rank_>subset[qroot].rank_) subset[qroot].parent=proot;
    else
    {
        subset[qroot].parent=proot;
        subset[proot].rank_++;
    }
    return true;
}
 
struct node{
    int vartex,cost;
};
 
vector<node> spanning_tree[mx_node];
void kruskal()
{
    sort(edges,edges+total_edge,cmpr);
    loop(0,total_node-1)
    {
        subset[lc].parent=lc;
        subset[lc].rank_=0;
    }
    loop(0,total_edge-1)
    {
        if( union_(edges[lc].u,edges[lc].v) )
        {
            spanning_tree[ edges[lc].u ].pb( {edges[lc].v,edges[lc].cost} );
            spanning_tree[ edges[lc].v ].pb( {edges[lc].u,edges[lc].cost} );
        }
    }
}
int ans[mx_node];
 
void dfs(int src,int cost)
{
    ans[src]=cost;
    for(int i=0;i<spanning_tree[src].size();i++)
    {
        if(ans[spanning_tree[src][i].vartex]==-1)
        {
            dfs(spanning_tree[src][i].vartex,max(cost,spanning_tree[src][i].cost)  );
        }
    }
}
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        sfii(total_node,total_edge);
        loop(0,total_edge-1)
        {
            sfiii(edges[lc].u,edges[lc].v,edges[lc].cost);
        }
        int src;
        sfi(src);
        kruskal();
        mem(ans,-1);
 
        dfs(src,0);
        casenonl;
        loop(0,total_node-1)
        {
            if(ans[lc]==-1) printf("Impossible\n");
            else pfie(ans[lc]);
            spanning_tree[lc].clear();
        }
    }
 
}
 