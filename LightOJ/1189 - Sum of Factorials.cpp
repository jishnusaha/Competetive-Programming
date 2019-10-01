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
#define sfl(def_var) scanf("%ld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%ld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define pfs(def_var) printf("%s",def_var)
 
 
int main()
{
    ll fact[21];
    fact[0]=1;
    loop(1,20)
    {
        fact[lc]=fact[lc-1]*lc;
    }
 
    int t;
    sfi(t);
    tloop(t)
    {
        ll n;
        sfl(n);
        int i=20;
        vector<int> v;
        while(i>=0)
        {
            if(fact[i]<=n)
            {
                n-=fact[i];
                v.push_back(i);
            }
            i--;
        }
        caseno;
        if(n!=0) pfs("impossible\n");
        else
        {
            bloop(v.size()-1,1)
            {
                pfi(v[blc]);
                pfs("!+");
            }
            pfi(v[0]);
            pfs("!\n");
        }
    }
}
 
