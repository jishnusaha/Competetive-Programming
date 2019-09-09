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
 
#define si(def_var) scanf("%d",&def_var)
#define sii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sl(def_var) scanf("%I64d",&def_var)
#define sd(def_var) scanf("%lf",&def_var)
#define ss(def_var) scanf("%s",&def_var)
 
#define pi(def_var) printf("%d",def_var)
#define pl(def_var) printf("%I64d",def_var)
#define pd(def_var) printf("%lf",def_var)
#define ps(def_var) printf("%s",def_var)
 
 
int main()
{
    int t;
    si(t);
    tloop(t)
    {
 
 
        int n,m;
        sii(n,m);
        int a[n][m];
        loop(0,n-1)
        {
            loop2(0,m-1) si(a[lc][lc2]);
        }
        int ans=0;
        loop(0,m-1) ans+=a[0][lc];
        loop(1,n-1)
        {
            int sum=0;
            loop2(0,m-1)
            {
                sum+=a[lc][lc2];
            }
            ans^=sum;
        }
        caseno;
        if(!ans) ps("Bob\n");
        else ps("Alice\n");
    }
 
}
 