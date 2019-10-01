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
#define sfc(def_var) scanf("%c",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%I64d",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define pfs(def_var) printf("%s",def_var)
 
double logN[1000001];
 
void initialize()
{
    logN[0]=0;
    logN[1]=0;
    loop(2,1000000)
    {
        logN[lc]=logN[lc-1]+log(lc);
    }
}
int main()
{
 
    initialize();
    int t;
    sfi(t);
    tloop(t)
    {
        int n,b;
        sfii(n,b);
        int ans=logN[n]/log(b)+1;
        caseno;
        pfie(ans);
    }
}