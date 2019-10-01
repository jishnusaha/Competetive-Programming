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
#define sfll(def_var,def_var2) scanf("%lld %lld",&def_var,&def_var2)
 
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        int n,m,k;
        sfii(n,m); sfi(k);
        int a[n][k];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                sfi(a[i][j]);
            }
        }
        int p;
        sfi(p);
        int f[40];
        loop(0,39) f[lc]=0;
        int c;
        loop(0,p-1)
        {
            sfi(c);
            f[c]++;
        }
        bool possible=true;
 
        for(int i=0;i<n;i++)
        {
            bool happy=false;
            for(int j=0;j<k;j++)
            {
 
                if(a[i][j]<0)
                {
                    if(f[ -a[i][j] ]==0)
                    {
                        happy=true;
                        break;
                    }
                }
                else
                {
                    if(f[ a[i][j] ]!=0)
                    {
                        happy=true;
                        break;
                    }
                }
            }
 
            if(!happy)
            {
                possible=false;
                break;
            }
        }
        caseno;
        if(possible) printf("Yes\n");
        else printf("No\n");
    }
}