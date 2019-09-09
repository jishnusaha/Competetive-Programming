/*
    (farthest node or largest path)
 
    procedure:
 
    for this problem <> 'underected graph with no cycle':
    if we start bfs from any node we will find a farthest node from that source,
    it will be a end node of our desired farthest path
    now if we again start bfs from the node we got earlier
    we will find the another node of that desired farthest path
 
 
    for directed graph with no cycle:(find largest path)
    for directed graph with no cycle we may not visit all nodes from a specific node.
    one procedure to solve this problem we have to call bfs for all nodes if they are not visited.
    for this we may use recursive bfs function
    similar problem: https://a...content-available-to-author-only...r.jp/contests/dp/tasks/dp_g
 
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
#define caseno printf("Case %d: ",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
 
 
int const node_size=30010;
pair<int,int> temp;
bool pushed[node_size];
int distance_from_source[node_size];

void BFS(int source,vector< pair<int,int> > adjancency_list[])
{
    for(int i=0;i<node_size;i++)
    {
        distance_from_source[i]=0;
        pushed[i]=false;
    }
    queue< pair<int,int> >q;
    q.push( make_pair(0,source) );
    pushed[source]=true;
    while(!q.empty())
    {
        temp=q.front(); ///for priority_queue front replaced by top();
        q.pop();
        int u=temp.second;
        for(int i=0;i<adjancency_list[u].size();i++)
        {
            int v=adjancency_list[u][i].second;
            int weight_u_TO_v=adjancency_list[u][i].first;
            if(!pushed[v])
            {
                distance_from_source[v]=distance_from_source[u]+weight_u_TO_v;
                q.push( adjancency_list[u][i] );
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
        int n;
        sfi(n);
        vector< pair<int,int> > adjancency_list[n];
        loop(1,n-1)
        {
            int u,v,w;
            sfii(u,v);
            sfi(w);
            adjancency_list[u].push_back( make_pair(w,v) ); ///make_pair(weight,node)
            adjancency_list[v].push_back( make_pair(w,u) ); ///make_pair(weight,node)
        }
        BFS(0,adjancency_list);
        int distance=0;
        int farthest_node_1=0,farthest_node_2;
        loop(0,n-1)
        {
            if(distance<distance_from_source[lc])
            {
                farthest_node_1=lc;
                distance=distance_from_source[lc];
            }
        }
        BFS(farthest_node_1,adjancency_list);
 
        distance=0;
        loop(0,n-1)
        {
            if(distance<distance_from_source[lc])
            {
                farthest_node_2=lc;
                distance=distance_from_source[lc];
            }
        }
        caseno; pfie(distance);
    }
}