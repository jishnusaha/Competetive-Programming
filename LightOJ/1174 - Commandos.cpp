/*
    idea:
        one node farthest from source may be closest to destination and otherwise
        so, for which node the traveling cost will be max it is not certain.
        to solve this problem
        for every node, we will calculate distance from source
                                      and distance form destination both
        the summation of both distance will be the traveling cost for this particular node.
        to the max summation will be the ans.
        simulate any graph; may lead to get this trick
 
 
 
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
#define caseno printf("Case %d: ",tlc);
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
 
 
vector<int>adj_list[110];
 
bool pushed[110];
 
int dist_src[110],dist_dest[110];
 
bool src;
 
void bfs(int source)
{
    queue< pair<int,int> > q;
    q.push(make_pair(source,0));
    pushed[source]=true;
    int u,v,cost;
    while(!q.empty())
    {
        u=q.front().first;
        cost=q.front().second;
        if(src) dist_src[u]=cost;
        else dist_dest[u]=cost;
        q.pop();
        for(int i=0;i<adj_list[u].size();i++)
        {
            v=adj_list[u][i];
            if(!pushed[v])
            {
                q.push(make_pair(v,cost+1 ));
                pushed[v]=true;
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
        int n,r,u,v;
        sfii(n,r);
        while(r--)
        {
            sfii(u,v);
            adj_list[u].pb(v);
            adj_list[v].pb(u);
        }
        int s,d;
        sfii(s,d);
 
        src=true;
        loop(0,104) pushed[lc]=false;
        bfs(s);
 
        src=false;
        loop(0,104) pushed[lc]=false;
        bfs(d);
 
        int mx=-1;
        loop(0,n-1)
        {
            mx=max(mx,dist_dest[lc]+dist_src[lc]);
            adj_list[lc].clear();
        }
        caseno;
        pfie(mx);
 
    }
}
 
