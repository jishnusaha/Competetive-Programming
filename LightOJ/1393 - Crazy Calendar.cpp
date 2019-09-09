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
 
int main()
{
 
    int t;
    scanf("%d",&t);
    tloop(t)
    {
        int r,c;
        scanf("%d %d",&r,&c);
        int ans=0,p;
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                scanf("%d",&p);
                int step=(r-i)+(c-j);
                if((step&1)) ans^=p;
            }
        }
        for(int j=1;j<c;j++)
        {
            scanf("%d",&p);
            if( ((c-j)&1) ) ans^=p;
        }
        scanf("%d",&p);
        caseno;
        if(!ans) printf("lose\n");
        else printf("win\n");
 
 
 
    }
}