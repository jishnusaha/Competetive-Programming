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
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
#define mx 1000100
 
int count_2[mx],count_5[mx];
 
int main()
{
 
    count_5[0]=0;
    for(int i=1;i<mx;i+=1)
    {
        int p=i;
        if(p%5==0)
        {
            count_5[i]=count_5[i-1]+1;
            p/=5;
            while(p%5==0)
            {
                count_5[i]++;
                p/=5;
            }
        }
        else count_5[i]=count_5[i-1];
    }
    count_2[0]=0;
    for(int i=1;i<mx;i++)
    {
        int p=i;
        if(p&1) count_2[i]=count_2[i-1];
        else
        {
            count_2[i]=count_2[i-1]+1;
            p/=2;
            while(p%2==0)
            {
                p/=2;
                count_2[i]++;
            }
        }
    }
    int t;
    sfi(t);
    tloop(t)
    {
        int n, r, p, q;
        sfii(n,r);
        sfii(p,q);
        ///nCr
        int c_5=count_5[n]-count_5[r]-count_5[n-r];
        int c_2=count_2[n]-count_2[r]-count_2[n-r];

        ///p^q
        int temp=p;
        int c=0;
        while(temp%5==0)
        {
            temp/=5;
            c++;
        }
        c_5+=c*q;
        c=0;
        while(p%2==0)
        {
            p/=2;
            c++;
        }
        c_2+=c*q;
 
        caseno; pfi( min(c_2,c_5) ); nl;
    }
}