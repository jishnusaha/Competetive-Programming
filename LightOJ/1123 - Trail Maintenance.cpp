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
 
#define mx_edges 6001
#define mx_node 201
 
int pos[201][201];
 
struct e{
    int u,v,cost;
}edges[mx_edges];
int total_node,total_edges;
 
bool cmpr(e b,e a)
{
    return b.cost<a.cost;
}
struct s{
    int parent, rank_;
 
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
 
    if(proot==qroot) return false;
 
    if(subset[proot].rank_<subset[qroot].rank_) subset[proot].parent=qroot;
    else if(subset[qroot].rank_<subset[proot].rank_) subset[qroot].parent=proot;
    else
    {
        subset[qroot].parent=proot;
        subset[proot].rank_++;
    }
    return true;
}
struct node{
    int vertex,cost;
};
 
vector<int> spanning_tree[mx_node];
int kruskal()
{
    int ans=0;
    loop(0,total_node)
    {
        subset[lc].parent=lc;
        subset[lc].rank_=0;
    }
    for(int i=0;i<total_edges;i++)
    {
        if(union_(edges[i].u,edges[i].v))
        {
            ans+=edges[i].cost;
            spanning_tree[ edges[i].u ].pb(edges[i].v  );
            spanning_tree[ edges[i].v ].pb(edges[i].u  );
        }
    }
    return ans;
}
 
bool pushed[mx_node];
void bfs(int src)
{
    pushed[src]=true;
    queue<int>q;
    q.push(src);
 
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<spanning_tree[u].size();i++)
        {
            int v=spanning_tree[u][i];
            if(!pushed[v])
            {
                pushed[v]=true;
 
                q.push(v);
            }
        }
    }
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        mem(pos,-1);
        int w;
        sfii(total_node,w);
        casenonl;
        total_edges=0;
        for(int wc=0;wc<w;wc++)
        {
            int u,v,cost;
            sfiii(u,v,cost);
            if(u>v) swap(u,v);
            if(pos[u][v]!=-1)
            {
                int p=pos[u][v];
                if(edges[p].cost>cost)
                {
                    edges[p].cost=cost;
                    while(p>0 && edges[p].cost<edges[p-1].cost)
                    {
                        swap(edges[p],edges[p-1]);
                        pos[edges[p].u ][edges[p].v ]=p;
                        p--;
                    }
                    pos[u][v]=p;
                }
            }
            else
            {
                edges[total_edges].u=u;
                edges[total_edges].v=v;
                edges[total_edges].cost=cost;
                int p=total_edges;
                while(p>0 && edges[p].cost<edges[p-1].cost)
                {
                    swap(edges[p],edges[p-1]);
                    pos[edges[p].u ][edges[p].v ]=p;
                    p--;
                }
                pos[u][v]=p;
                total_edges++;
            }
            int ans=kruskal();
            bfs(1);
            int visit=0;
            loop(1,total_node)
            {
                if(pushed[lc])visit++;
                pushed[lc]=false;
                spanning_tree[lc].clear();
            }
            if(visit==total_node) pfie(ans);
            else pfie(-1);
        }
    }
}
 