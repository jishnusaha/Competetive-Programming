/*
    idea:
        storing adj_matrix ans
                    connected_node
                    weight
                    max cost through this edge
        suppose, node 5 hast 3 connected node. 1 2 4 and cost 10,20,30 respectively
                then,through 5-1 connecting edge we can cover maximum 60 weight 5 to farthest node on that path(there may be more node after 1)
                    through 5-2 connecting edge we can cover maximum 69 weight 5 to farthest node on that path(there may be more node after 2)
                    through 5-2 connecting edge we can cover maximum 54 weight 5 to farthest node on that path(there may be more node after 4)
                SO  farthest cost from node 5 will be 69,
 
        now suppose, if node 2 has two connected node 7,8 with cost 10,15 respectively
                then through, 2-7 connecting edge we can cover maximum 30 weight
                     through, 2-8 connecting edge we can cover maximum 35 weight
                now, suppose 11 be the farthest node of the path which start from 5 and go through 5-1 edge
 
                so, length of 2-11 will be
                    2 to 5 + 5 to 11
                       20  + 60
 
                        in this case we don't need to calculate 5 to 11 if we already have calculate it for 5. just add simply.
                        this is the overlapping sub problem 5 to 11 calculation can be optimize by DP
 
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
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n,w;
        sfii(n,w);
        int a[n],p;
        loop(0,n-1)
        {
            sfii(p,a[lc]);
        }
        sort(a,a+n);
        int mv=1,dust_done=a[0]+w;
 
        for(int i=1;i<n;i++)
        {
            if(a[i]>dust_done)
            {
                mv++;
                dust_done=a[i]+w;
            }
        }
        caseno; pfie(mv);
 
    }
}