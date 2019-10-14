
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

#define pii pair< int,int >
#define pll pair< long long, long long >
#define pib pair< int,bool >

#define casenos printf("Case %d: ",tlc);
#define casenonl printf("Case %d:\n",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))


#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)

#define sfl(def_var) scanf("%lld",&def_var)
#define sfll(def_var,def_var2) scanf("%lld %lld",&def_var,&def_var2)
#define sflll(def_var,def_var2,def_var3) scanf("%lld %lld %lld",&def_var,&def_var2,&def_var3)

#define sfd(def_var) scanf("%lf",&def_var)


#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfis(def_var) printf("%d ",def_var)

#define pfle(def_var) printf("%lld\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfls(def_var) printf("%lld ",def_var)

#define pfd(def_var) printf("%lf",def_var)

#define nl printf("\n");

#define casenownl output << "Case " << tlc << ":\n";
#define casenows output << "Case " << tlc << ": ";

#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
#define BOOST		ios_base::sync_with_stdio(false);cin.tie(NULL)


#define A 0
#define C 1
#define G 2
#define T 3

struct node{
    int total_DNA_this_path=0;
    node* next[4];
    node()
    {
        loop(0,3) next[lc]=NULL;
    }
}* root;

void _insert(string s)
{
    node* curr=root;
    for(int i=0;i<s.size();i++)
    {
        int id;
        if(s[i]=='A') id=A;
        if(s[i]=='C') id=C;
        if(s[i]=='G') id=G;
        if(s[i]=='T') id=T;

        if(curr->next[id]==NULL)
        {
            curr->next[id]=new node();
        }
        curr=curr->next[id];
        curr->total_DNA_this_path++;
    }
}

int find_ans(node* curr,int dept=0)
{
    int ret=dept*curr->total_DNA_this_path;

    for(int i=0;i<4;i++)
    {
        if(curr->next[i])
            ret=max(ret,find_ans(curr->next[i],dept+1));
    }
    return ret;
}
void _delete(node* curr)
{
    for(int i=0;i<4;i++)
    {
        if(curr->next[i])
            _delete(curr->next[i]);
    }
    delete(curr);
}

int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n;
        sfi(n);
        string s;
        root=new node();
        while(n--)
        {
            cin >> s;
            _insert(s);
        }
        casenos;
        pfie(find_ans(root));
        _delete(root);
    }
}
