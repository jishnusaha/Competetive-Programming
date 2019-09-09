/*
 
    idea:
        in a tree if we calculate the farthest 2 nodes. let define them mx1,mx2
        then, from any arbitrary  node p, the farthest path from p will be
        max( distance from p to mx1,distance from p to mx2 )
       
        so, if we calculate mx1 and mx2
        then calculate all node's distance from mx1 and store in a array
        then calculate all node's distance from mx2 and store in another array
        then we can get ans from the maximum value between those 2 array
 
 
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
#define caseno printf("Case %d:\n",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
int n;
struct data{
    int connected_node,weight;
};
 
vector<data>adj_list[30010];
bool taken[30010];
int dist1[30010];
int dist2[30010];
 
bool dist2call=false;
 
void dfs(int source,int cost)
{
    taken[source]=true;
    for(int i=0;i<adj_list[source].size();i++)
    {
        if(!taken[ adj_list[source][i].connected_node ])
        {
            dfs(adj_list[source][i].connected_node,cost+adj_list[source][i].weight);
        }
    }
    taken[source]=false;
    if(dist2call) dist2[source]=cost;
    else dist1[source]=cost;
 
}
 
int main()
{
    int t,u,v,w;
    data p;
    sfi(t);
    tloop(t)
    {
        sfi(n);
 
        loop(1,n-1)
        {
            sfiii(u,v,w);
            p.connected_node=u;
            p.weight=w;
            adj_list[v].pb(p);
            p.connected_node=v;
            adj_list[u].pb(p);
        }
 
        dist2call=false;
        dfs(0,0);
 
        int farthest_node1,farthest_node2,mx=-1;
        loop(0,n-1)
        {
            if(dist1[lc]>mx)
            {
                farthest_node1=lc;
                mx=dist1[lc];
            }
        }
 
        dfs(farthest_node1,0);
        mx=-1;
        loop(0,n-1)
        {
            if(dist1[lc]>mx)
            {
                farthest_node2=lc;
                mx=dist1[lc];
            }
        }
 
        dist2call=true;
        dfs(farthest_node2,0);
 
        caseno;
        loop(0,n-1)
        {
            pfie(max(dist1[lc],dist2[lc]));
            dist1[lc]=dist2[lc]=0;
            adj_list[lc].clear();
        }
    }
}