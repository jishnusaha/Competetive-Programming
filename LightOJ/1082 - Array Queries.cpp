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
 
void init_min(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init_min(Left, b, mid);
    init_min(Right, mid + 1, e);
    tree[node] =min( tree[Left] , tree[Right]);
}
int query_min(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) return INT_MAX;
    if (b >= i && e <= j) return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query_min(Left, b, mid, i, j);
    int p2 = query_min(Right, mid + 1, e, i, j);
    return min(p1,p2);
}
void update_min(int node, int b, int e, int i, int newvalue)
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
    update_min(Left, b, mid, i, newvalue);
    update_min(Right, mid + 1, e, i, newvalue);
    tree[node] = min( tree[Left] , tree[Right]);
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n,q;
        sfii(n,q);
        loop(1,n) sfi(arr[lc]);
        init_min(1,1,n);
        caseno; nl;
        while(q--)
        {
            int i,j;
            sfii(i,j);
            pfi(query_min(1,1,n,i,j)); nl;
        }
    }
 
}