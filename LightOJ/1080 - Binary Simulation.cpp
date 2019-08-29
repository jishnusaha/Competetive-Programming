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
string s;
 
struct info
{
    char sum;
    bool prop=true;
}tree[mx * 3];
 
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].sum =s[b] ;
        //cout << "node : " << node << " value : "<< s[b] << endl;
        tree[node].prop = true;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].prop=true;
}
void update(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].prop = !tree[node].prop;
        //cout << "node " << node << " prop : "<< tree[node].prop << endl;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j);
    update(Right, mid + 1, e, i, j);
}
 
char query(int node, int b, int e, int i, bool carry=true)
{
    //cout << "query called for node : " << node << " b " << b << " e " << e << " i " << i << " carry " << carry << endl;
    if (i > e || i < b)
    {
        //cout << "out of range... return u\n";
        return 'u';
    }
    if(b==e)
    {
        //cout << "found\n";
        bool mycarry=tree[node].prop;
        //cout << "mycarry : " << mycarry << " called carry : " << carry << endl;
        if(mycarry==false && carry==false) carry=true;
        else if(mycarry==false && carry==true) carry=false;
        //else if(mycarry==true && carry==true) carry=true;
        //else if(mycarry==true && carry==false) carry=false;
       // cout << "update carry : " << carry << endl;
 
 
 
       // cout << " actual value : " << tree[node].sum << endl;
 
        if(carry) return tree[node].sum;
        else
        {
            if(tree[node].sum=='1') return '0';
            else return '1';
        }
    }
 
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    bool mycarry=tree[node].prop;
    if(mycarry==false && carry==false) carry=true;
    else if(mycarry==false && carry==true) carry=false;
    //else if(mycarry==true && carry==true) carry=true;
    //else if(mycarry==true && carry==false) carry=false;
 
   // cout << "calling query for node " << Left << " with carry : " << carry << endl;
    char p1 = query(Left, b, mid, i, carry );
   // cout << "returned " << p1 << " for node " << Left << endl;;
   // cout << "calling query for node " << Right << " with carry : " << carry << endl;
    char p2 = query(Right, mid + 1, e, i, carry );
   // cout << "returned " << p2 << " for node " << Right << endl;;
 
    //cout << "for node " << node << " returning\n";
 
    if(p1!='u' || p2!='u')
    {
        if(p1=='u') return p2;
        else return p1;
    }
    else return 'u';
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        //cin.ignore();
        cin >> s;
        //cout << "input  : " << s << endl;
        init(1,0,s.size()-1);
        int q;
        sfi(q);
        caseno;nl;
        while(q--)
        {
            char c;
            //cin.ignore();
            //cin >>c;
            scanf(" %c",&c);
 
            //cout << "input  : " << c << endl;
            if(c=='I')
            {
                int i,j;
                sfii(i,j);
                //cout << "i : " << i << " j  : " <<  j << endl;
                update(1,0,s.size()-1,i-1,j-1);
            }
            else
            {
                int i;
                sfi(i);
                //cout << "i : " << i << endl;
                printf("%c\n",query(1,0,s.size()-1,i-1) );
            }
        }
 
    }
 
}