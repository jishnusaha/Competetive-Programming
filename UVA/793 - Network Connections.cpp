

    /*------------------DSU---------------*/

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

#define casenos printf("Case #%d: ",tlc);
#define casenonl printf("Case %d:\n",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))


#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)

#define sfl(def_var) scanf("%I64d",&def_var)
#define sfll(def_var,def_var2) scanf("%I64d %I64d",&def_var,&def_var2)
#define sflll(def_var,def_var2,def_var3) scanf("%I64d %I64d %I64d",&def_var,&def_var2,&def_var3)

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

#define debug cout

#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
#define BOOST		ios_base::sync_with_stdio(false);cin.tie(NULL)

map<int,int>representative;

int find_representative(int x)
{
    if(representative[x]!=x) representative[x]=find_representative(representative[x]);
    return representative[x];
}

void _union(int x,int y)
{
    int rep_x=find_representative(x);
    int rep_y=find_representative(y);
    if(rep_x!=rep_y) representative[rep_x]=rep_y;
}
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n;
        string s;
        sfi(n);
        int yes=0,no=0;
        representative.clear();
        cin.ignore();
        while(getline(cin,s))
        {
            if(s.size()==0) break;
            int a=0,b=0;
            int i=2;
            for(;s[i]!=' ';i++) a=a*10+(int)(s[i]-'0');
            for(i++;i<s.size();i++) b=b*10+(int)(s[i]-'0');

            if(representative.find(a)==representative.end()) representative[a]=a;
            if(representative.find(b)==representative.end()) representative[b]=b;

            if(s[0]=='c') _union(a,b);
            else
            {
                int rep_a=find_representative(a);
                int rep_b=find_representative(b);
                if(rep_a==rep_b) yes++;
                else no++;
            }
        }
        cout << yes << ',' << no << endl;
        if(tlc<t) cout << endl;
    }
}
