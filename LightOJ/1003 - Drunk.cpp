/*
    idea:
    notice the output changes from the input.
 
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
 
 
map<string ,int>mymap;
vector<int>adj_list[20100];
 
int in_degree[20100];
int visited_node=0;
 
queue<int>q;
void visit()
{
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj_list[u].size();i++)
        {
            int v=adj_list[u][i];
            in_degree[v]--;
            if(in_degree[v]==0) q.push(v);
        }
        q.pop();
        visited_node++;
    }
 
}
 
 
int main()
{
 
    int t;
    sfi(t);
    tloop(t)
    {
        int m;
        sfi(m);
        string data[m][2];
        int parent[m],parent_size=0;
        loop(0,m-1)
        {
            cin >> data[lc][0] >> data[lc][1];
            if(mymap.find(data[lc][0] )==mymap.end() )
            {
                int sz=mymap.size();
                parent[ parent_size++ ]=sz;
                mymap[ data[lc][0] ]=sz;
            }
            if(mymap.find(data[lc][1] )==mymap.end() )
            {
                int sz=mymap.size();
                mymap[ data[lc][1] ]=sz;
            }
            int u=mymap[ data[lc][0] ],v=mymap[ data[lc][1] ];
 
            in_degree[v]++;
            adj_list[u].push_back(v);
 
        }
 
        visited_node=0;
        loop(0,parent_size-1)
        {
            if(in_degree[ parent[lc] ]==0) q.push(parent[lc]);
        }
        visit();
        caseno;
        if(visited_node==mymap.size()) printf("Yes\n");
        else printf("No\n");
 
 
        loop(0,20100-1)
        {
            in_degree[lc]=0;
            adj_list[lc].clear();
        }
        mymap.clear();
    }
}
 