#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int lc=i;lc<=n;lc++)
#define tloop(tn) for(int tlc=1;tlc<=tn;tlc++)
#define loop2(i2,n2) for(int lc2=i2;lc2<=n2;lc2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(true)
#define pi acos(-1)
#define rad_to_deg(angl) ((180*angl)/pi)
#define ll long long
#define caseno printf("Case %d: ",tlc);

#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfl(def_var) scanf("%I64d",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)

#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%I64d",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define pfs(def_var) printf("%s",def_var)


int main()
{
    vector<ll> limit;
    limit.push_back(9);
    while(limit[limit.size()-1]<=429496729)
    {
        if(limit.size()&1) limit.push_back(limit[limit.size()-1]*2);
        else limit.push_back(limit[limit.size()-1]*9);
    }
    ll n;
    while(cin >> n)
    {
        int pos=lower_bound(limit.begin(),limit.end(),n)-limit.begin();
        if(pos&1) pfs("Ollie wins.\n");
        else pfs("Stan wins.\n");
    }
}