/*
    make 2 MST. MAXIMUM SPANNING TREE
                MINIMUM SPANNING TREE
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
 
#define mx_node 101
#define mx_edge 12001
 
int total_node,total_edges;
 
struct e{
    int u,v,w;
}edges[mx_edge];
bool cmpr(e b,e a)
{
    return b.w<a.w;
}
bool cmpr2(e b,e a)
{
    return b.w>a.w;
}
struct s{
    int parent,rank_;
 
}subset[mx_node];
int find_root(int x)
{
    if(subset[x].parent!=x) subset[x].parent=find_root(subset[x].parent);
    return subset[x].parent;
}
bool union_(int p,int q)
{
    int proot=find_root(p);
    int qroot=find_root(q);
 
    if(proot==qroot) return false;
    if(subset[proot].rank_<subset[qroot].rank_) subset[proot].parent=qroot;
    else if(subset[proot].rank_>subset[qroot].rank_) subset[qroot].parent=proot;
    else
    {
        subset[proot].parent=qroot;
        subset[qroot].rank_++;
    }
    return true;
 
}
int kruskal()
{
    loop(0,total_node)
    {
        subset[lc].parent=lc;
        subset[lc].rank_=0;
    }
 
    int ans=0;
    for(int i=0;i<total_edges;i++)
    {
        if(union_(edges[i].u,edges[i].v))
        {
            ans+=edges[i].w;
        }
    }
    return ans;
}
 
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        sfi(total_node);
        total_edges=0;
        while(cin >> edges[total_edges].u >> edges[total_edges].v >> edges[total_edges].w )
        {
            if(edges[total_edges].u==0 && edges[total_edges].v==0 && edges[total_edges].w==0)
            {
                break;
            }
            total_edges++;
        }
        sort(edges,edges+total_edges,cmpr);
        int ans=kruskal();
        sort(edges,edges+total_edges,cmpr2);
        ans+=kruskal();
        casenos;
        if(ans&1) printf("%d/2\n",ans);
        else pfie(ans/2);
    }
}