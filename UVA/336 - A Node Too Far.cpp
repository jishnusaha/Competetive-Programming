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

#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
#define BOOST		ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<int> adj_list[32];

int found=0;
int visited[32][2];

void dfs(int source,int t)
{
    visited[source][0]=1;
    if(visited[source][1]==-1) found++;
    visited[source][1]=t;

    if(t==0) return;

    for(int i=0;i<adj_list[source].size();i++)
    {
        if(visited[ adj_list[source][i]  ][0]==0 || ( visited[ adj_list[source][i]  ][0]==1 && visited[ adj_list[source][i]  ][1]<t ))
        {
            dfs(adj_list[source][i],t-1);
        }
    }
}

int tlc=1;
int main()
{
    while(1)
    {
        int n;
        sfi(n);
        if(!n) return 0;

        map<int,int>mp;
        int c=1,u,v,u_pos,v_pos;
        for(int i=0;i<n;i++)
        {
            sfii(u,v);
            if(mp.find(u)==mp.end())
            {
                mp[u]=c++;
            }
            if(mp.find(v)==mp.end())
            {
                mp[v]=c++;
            }
            adj_list[mp[v] ].pb(mp[u]);
            adj_list[mp[u] ].pb(mp[v]);
        }
        int node,t;
        while(cin >> node >> t)
        {
            if(node==0 && t==0) break;
            found=0;
            for(int i=0;i<c;i++)
            {
                visited[i][0]=0;
                visited[i][1]=-1;
            }
            int start;
            if(mp.find(node)==mp.end())
            {
                mp[node]=c++;
            }
            dfs(mp[node],t);
            casenos;
            printf("%d nodes not reachable from node %d with TTL = %d.\n",c-1-found,node,t);
            tlc++;
        }


        for(int i=0;i<c;i++) adj_list[i].clear();
    }
}
