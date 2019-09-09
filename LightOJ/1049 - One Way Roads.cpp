/*
    idea:
        calculate total forward path cost and backward path cost.
        ans is the minimum one
 
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
 
struct data{
    int node,cost;
    bool in;
};
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n,u,v,cost;
        sfi(n);
        vector<data> adj_list[n+1];
        data p;
        loop(1,n)
        {
            sfiii(u,v,cost);
 
            p.node=v,p.in=false,p.cost=cost;
            adj_list[u].pb(p);
 
            p.node=u,p.in=true;
            adj_list[v].pb(p);
        }
        int start_node=1,prev_node=1,curr_node=adj_list[1][0].node;
        int true_path_cost=adj_list[1][0].cost,false_path_cost=0;
        bool start_path=adj_list[1][0].in,taken_path_according_to_curr=!adj_list[1][0].in;
 
        while(1)
        {
            if(curr_node==start_node)
            {
                break;
            }
            if(adj_list[curr_node][0].node==prev_node)
            {
                if(adj_list[curr_node][1].in==start_path)
                {
                    true_path_cost+=adj_list[curr_node][1].cost;
                }
                else
                {
                    false_path_cost+=adj_list[curr_node][1].cost;
                }
                int temp=adj_list[curr_node][1].node;
                prev_node=curr_node;
                curr_node=temp;
            }
            else
            {
                if(adj_list[curr_node][0].in==start_path)
                {
                    true_path_cost+=adj_list[curr_node][0].cost;
                }
                else
                {
                    false_path_cost+=adj_list[curr_node][0].cost;
                }
                int temp=adj_list[curr_node][0].node;
                prev_node=curr_node;
                curr_node=temp;
            }
        }
        caseno;
        pfie(min(false_path_cost,true_path_cost));
    }
}
 