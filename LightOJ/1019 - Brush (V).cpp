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
 
int n,m;
struct s{
    int connected_node,cost;
};
 
vector<s> adj_list[101];
int dist_from_src[101];
 
bool popped[101];
void dijkstra(int src)
{
    loop(1,n)
    {
        popped[lc]=false;
        dist_from_src[lc]=INT_MAX;
    }
    dist_from_src[src]=0;
    priority_queue< pair<int,int> >q;
    q.push({0,src});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        popped[u]=true;
        for(int i=0;i<adj_list[u].size();i++)
        {
            int v=adj_list[u][i].connected_node;
            int cost_u_to_v=adj_list[u][i].cost;
 
            if(dist_from_src[v]>dist_from_src[u]+cost_u_to_v && !popped[v])
            {
                dist_from_src[v]=dist_from_src[u]+cost_u_to_v;
                q.push( {-dist_from_src[v],v});
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
        sfii(n,m);
        s temp;
        int u,v;
        while(m--)
        {
            sfiii(u,v,temp.cost);
            temp.connected_node=v;
            adj_list[u].pb(temp);
            temp.connected_node=u;
            adj_list[v].pb(temp);
        }
        dijkstra(1);
        casenos;
        if(dist_from_src[n]==INT_MAX) printf("Impossible\n");
        else pfie(dist_from_src[n]);
        loop(1,n) adj_list[lc].clear();
    }
}
 