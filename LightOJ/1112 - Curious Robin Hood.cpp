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
#define caseno printf("Case %d:",tlc);
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
#define mx 100021
int arr[mx];
int tree[mx * 3];
void init_sum(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init_sum(Left, b, mid);
    init_sum(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query_sum(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) return 0;
    if (b >= i && e <= j) return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query_sum(Left, b, mid, i, j);
    int p2 = query_sum(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update_sum(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)return;
    if (b >= i && e <= i)
    {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update_sum(Left, b, mid, i, newvalue);
    update_sum(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n,q;
        sfii(n,q);
        loop(0,n-1) sfi(arr[lc]);
        init_sum(1,0,n-1);
        caseno;nl;
        while(q--)
        {
            int type;
            sfi(type);
            if(type==1)
            {
                int i;
                sfi(i);
                pfi(query_sum(1,0,n-1,i,i)); nl;
                update_sum(1,0,n-1,i,0);
            }
            else if(type==2)
            {
                int i,v;
                sfii(i,v);
                v+=query_sum(1,0,n-1,i,i);
                update_sum(1,0,n-1,i,v);
            }
            else
            {
                int i,j;
                sfii(i,j);
                pfi(query_sum(1,0,n-1,i,j)); nl;
            }
        }
    }
 
}