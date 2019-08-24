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
 
 
    int t;
    sfi(t);
    tloop(t)
    {
 
        int n;
        sfi(n);
        int a[n];
        loop(0,n-1) sfi(a[lc]);
        sort(a,a+n);
        int c=0;
        loop(0,n-2)
        {
            loop2(lc+1,n-1)
            {
                int mini=abs(a[lc]-a[lc2])+1;
                int maxi=abs(a[lc]+a[lc2])-1;
                int lw=lower_bound(a+lc2,a+n,mini)-a;
                int up=upper_bound(a+lc2,a+n,maxi)-a;
                c+=up-lw;
                if(lw<=lc && up>=lc) c--;
                if(lw<=lc2 && up>=lc2) c--;
       
            }
        }
        caseno;
        printf("%d\n",c);
 
    }
}