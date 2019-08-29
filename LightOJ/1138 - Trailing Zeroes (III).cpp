#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int lc=i;lc<=n;lc++)
#define tloop(tn) for(int tlc=1;tlc<=tn;tlc++)
#define loop2(i2,n2) for(int lc2=i2;lc2<=n2;lc2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
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
 
ll count_zero(ll n)
{
    int res=0;
    while(n)
    {
        res+=n/5;
        n/=5;
    }
    return res;
}
 
int main()
{
    int t;
    cin >> t;
    tloop(t)
    {
 
        ll q;
        cin >> q;
        ll low=1,high=INT_MAX,ans=0;
        while(low<=high)
        {
            //cout << "low : " << low << ". high : " << high;
            ll mid=(low+high)/2;
            ll zero=count_zero(mid);
            //cout << ". mid : " << mid << ". zero : " << zero << endl;
            if(q<=zero)
            {
                if(zero==q) ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        caseno;
        if(ans) cout << ans << endl;
        else pfs("impossible\n");
        //pfs("\n");
    }
}