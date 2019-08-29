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


string s;
int r;

char ans[100];
void solve(int pos,string ans)
{
    if(ans.size()==r)
    {
        cout << ans << endl;
        return;
    }
    if(pos==s.size()) return;

    for(int i=pos;i<s.size();i++)
    {
        if(i>pos)
        {
            if(s[i]==s[i-1]) continue; ///from this position if we taken a char one times then no need to take it again.
        }

        solve(i+1,ans+s[i]);
    }


}

int main()
{
    while(cin >> s >> r)
    {
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            string p="";
            p+=s[i];
            if(i>0)
            {
                if(s[i]==s[i-1]) continue; ///if we already started with that char then no need to start again
            }
            solve(i+1,p);
        }
    }
}