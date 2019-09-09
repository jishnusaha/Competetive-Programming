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
#define pfis(def_var) printf("%d ",def_var)
 
#define pfle(def_var) printf("%lld\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfls(def_var) printf("%lld ",def_var)
 
#define pfd(def_var) printf("%lf",def_var)
 
#define nl printf("\n");
 
vector<int>adj_list[1001];
 
int reach[1001];
bool visited[1001];
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    reach[source]++;
    visited[source]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj_list[u].size();i++)
        {
            int v=adj_list[u][i];
            if(!visited[v])
            {
                reach[v]++;
                q.push(v);
                visited[v]=true;
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
        int k,n,m,p;
        sfiii(k,n,m);
 
        set<int>source;
        loop(0,k-1)
        {
            sfi(p);
            source.insert(p);
        }
        int u,v;
        loop(1,m)
        {
            sfii(u,v);
            adj_list[u].pb(v);
        }
       
        for(set<int>::iterator it=source.begin();it!=source.end();it++)
        {
            loop(0,n) visited[lc]=false;
            bfs(*it);
        }
        int ans=0,need=source.size();
        loop(1,n)
        {
            if(reach[lc]==need) ans++;
            reach[lc]=0;
            adj_list[lc].clear();
        }
        caseno; pfie(ans);
 
    }
}