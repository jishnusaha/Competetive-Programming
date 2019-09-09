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
 
#define mx_node 201
 
int total_node,total_edge;
 
struct s{
    int u,v,cost;
};
 
int main()
{
 
    int t;
    sfi(t);
    s temp;
    tloop(t)
    {
        sfi(total_node);
        int a[total_node+1];
 
        vector< s >edges;
        int distance_from_src[total_node+1];
        int ans[total_node+1];
 
 
        loop(1,total_node) sfi(a[lc]);
        sfi(total_edge);
        loop(1,total_edge)
        {
            sfii(temp.u,temp.v);
            temp.cost=(a[temp.v]-a[temp.u])*(a[temp.v]-a[temp.u])*(a[temp.v]-a[temp.u]);
            edges.pb(temp);
        }
 
        int src=1;
        ///bellman ford:
 
        for(int i=1;i<=total_node;i++) distance_from_src[i]=INT_MAX;
 
        distance_from_src[src]=0;
        int u,v,cost;
        ///relaxing path for n-1 times
        for(int p=1;p<total_node;p++)
        {
            for(int i=0;i<edges.size();i++)
            {
                u=edges[i].u,v=edges[i].v ,cost=edges[i].cost;
                if(distance_from_src[v]>distance_from_src[u]+cost && distance_from_src[u]!=INT_MAX)
                {
                    distance_from_src[v]=distance_from_src[u]+cost;
                }
            }
        }
 
        loop(1,total_node) ans[lc]=distance_from_src[lc];
        ///if negative cycle exists, marking the nodes goes through negative cycle
        for(int p=1;p<total_node;p++)
        {
            bool update=false;
            for(int i=0;i<edges.size();i++)
            {
                update=true;
                u=edges[i].u,v=edges[i].v ,cost=edges[i].cost;
                if(distance_from_src[v]>distance_from_src[u]+cost && distance_from_src[u]!=INT_MAX)
                {
                    ans[v]=0;
                    distance_from_src[v]=distance_from_src[u]+cost;
                }
            }
            if(!update) break;
        }
 
 
        int q;
        sfi(q);
        casenonl;
        while(q--)
        {
            int p;
            sfi(p);
            if(ans[p]<3 || ans[p]==INT_MAX) printf("?\n");
            else pfie(ans[p]);
        }
    }
}
 