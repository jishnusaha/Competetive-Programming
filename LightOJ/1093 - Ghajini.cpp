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
int tree_max[mx * 3];
int tree_min[mx * 3];
 
void init_min(int node, int b, int e)
{
    if (b == e) {
        tree_min[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init_min(Left, b, mid);
    init_min(Right, mid + 1, e);
    tree_min[node] =min( tree_min[Left] , tree_min[Right]);
}
int query_min(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) return INT_MAX;
    if (b >= i && e <= j) return tree_min[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query_min(Left, b, mid, i, j);
    int p2 = query_min(Right, mid + 1, e, i, j);
    return min(p1,p2);
}
 
void init_max(int node, int b, int e)
{
    if (b == e) {
        tree_max[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init_max(Left, b, mid);
    init_max(Right, mid + 1, e);
    tree_max[node] =max( tree_max[Left] , tree_max[Right]);
}
int query_max(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) return INT_MIN;
    if (b >= i && e <= j) return tree_max[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query_max(Left, b, mid, i, j);
    int p2 = query_max(Right, mid + 1, e, i, j);
    return max(p1,p2);
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n,d;
        sfii(n,d);
        loop(0,n-1) sfi(arr[lc]);
        init_max(1,0,n-1);
        init_min(1,0,n-1);
        int ans=INT_MIN;
        int i=0;
        for(i=0;i+d-1<n;i++)
        {
            int p1=query_max(1,0,n-1,i,i+d-1);
            int p2=query_min(1,0,n-1,i,i+d-1);
 
            ans=max(ans, abs(p1-p2));
        }
        if(i<n-1)
        {
            int p1=query_max(1,0,n-1,i,n-1);
            int p2=query_min(1,0,n-1,i,n-1);
            ans=max(ans, abs(p1-p2));
        }
        caseno; pfi(ans); nl;
    }
}
 