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
    ll a;
    while(cin >> a)
    {
        if(!a) break;
        ll sqrta,d,p=0;
        bool found=false;
        if(a<0)
        {
            a=-a;
            sqrta=sqrt(a);
            sqrta=-sqrta;
            a=-a;
            for(ll d=-2;d>=sqrta;d--)
            {
                ll temp=a;p=0;
                while(temp%d==0)
                {
                    temp/=d; p++;
                }
                if(temp==1) {found=true; break;}
            }
        }
        else
        {
            sqrta=sqrt(a);
            d=2;
            for(;d<=sqrta;d++)
            {
                ll temp=a;p=0;
                while(temp%d==0)
                {
                    temp/=d; p++;
                }
                if(temp==1) {found=true; break;}
            }
        }
        if(found) cout << p << endl;
        else cout << 1 << endl;
    }
}