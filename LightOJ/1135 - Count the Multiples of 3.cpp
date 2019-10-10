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
#define casenos printf("Case %d: ",tlc);
#define casenonl printf("Case %d:\n",tlc);
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

#define mx 100021

struct data{
    int one=0,two=0,zero=0,lazy=0;
};

data tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].one=0;
        tree[node].two=0;
        tree[node].zero=1;
        tree[node].lazy=0;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2,right=node*2+1;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[left].two+tree[right].two;
    tree[node].zero=tree[left].zero+tree[right].zero;
}

void propagate_lazy_to_child(int node,int b,int e)
{
    if(b!=e)
    {
        int left=node*2,right=node*2+1;
        tree[left].lazy+=tree[node].lazy;
        tree[right].lazy+=tree[node].lazy;
        tree[left].lazy%=3;
        tree[right].lazy%=3;
    }
    if(tree[node].lazy==1)
    {
        int temp =tree[node].zero;
        tree[node].zero=tree[node].two;
        tree[node].two=tree[node].one;
        tree[node].one=temp;
    }
    if(tree[node].lazy==2)
    {
        int temp =tree[node].zero;
        tree[node].zero=tree[node].one;
        tree[node].one=tree[node].two;
        tree[node].two=temp;
    }
    tree[node].lazy=0;
}

int query(int node,int b,int e,int i,int j)
{
    if(tree[node].lazy) propagate_lazy_to_child(node,b,e);
    
    if(e<i || b>j) return 0;
    if(i<=b && j>=e) return tree[node].zero;

    int mid=(b+e)/2;
    int left=node*2,right=node*2+1;
    int ans=query(left,b,mid,i,j)+query(right,mid+1,e,i,j);

    tree[node].one=tree[left].one+tree[right].one;
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].two=tree[left].two+tree[right].two;
    return ans;
}

void update(int node,int b,int e,int i,int j)
{
    if(tree[node].lazy) propagate_lazy_to_child(node,b,e);
    
    if(e<i || b>j) return;
    if(i<=b && j>=e)
    {
        if(b!=e)
        {
            tree[node*2].lazy++;
            tree[node*2+1].lazy++;
            tree[node*2].lazy%=3;
            tree[node*2+1].lazy%=3;
        }
        int temp=tree[node].zero;
        tree[node].zero=tree[node].two;
        tree[node].two=tree[node].one;
        tree[node].one=temp;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2,right=node*2+1;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    tree[node].one=tree[left].one+tree[right].one;
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].two=tree[left].two+tree[right].two;

}

int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n,q;
        sfii(n,q);
        loop(0,mx*3-1)
        {
            tree[lc].lazy=0;
            tree[lc].one=0;
            tree[lc].two=0;
            tree[lc].zero=0;
        }
        init(1,1,n);

        casenonl;
        while(q--)
        {
            int type,i,j;
            sfiii(type,i,j);
            i++,j++;
            if(type)
            {
                pfie(query(1,1,n,i,j));

            }
            else
            {
                update(1,1,n,i,j);
            }
        }

    }
}
