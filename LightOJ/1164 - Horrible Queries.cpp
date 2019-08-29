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
 
struct info
{
    long long prop=0,sum=0;
}tree[mx*3];
int arr[mx];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(e+b)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=0;
}
void init_c(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=0;
        tree[node].prop=0;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(e+b)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=0;
    tree[node].prop=0;
}
 
 
 
void update(int node,int b,int e,int i,int j,long long newvalue)
{
    if(b>j || e<i) return;
    if(b>=i && e<=j)
    {
        tree[node].prop+=newvalue;
        tree[node].sum+=(e-b+1)*newvalue;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,newvalue);
    update(right,mid+1,e,i,j,newvalue);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
 
}
long long query(int node,int b,int e,int i ,int j,long long carry=0)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j)
    {
        return tree[node].sum+(e-b+1)*carry;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    long long p1=query(left,b,mid,i,j,carry+tree[node].prop);
    long long p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n,q;
        sfii(n,q);
        loop(0,n-1)arr[lc]=0;
        init(1,0,n-1);
        caseno;nl;
        while(q--)
        {
            int c;
            sfi(c);
            if(c==0)
            {
                int x, y, v;
                sfii(x,y);
                sfi(v);
                update(1,0,n-1,x,y,v);
            }
            else
            {
                int x,y;
                sfii(x,y);
                pfl(query(1,0,n-1,x,y)  ); nl;
            }
        }
        //init_c(1,0,n-1);
        for(int i=0;i<mx*3;i++)
        {
            tree[i].sum=0,tree[i].prop=0;
        }
    }
}