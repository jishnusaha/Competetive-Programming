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
#define pb push_back
 
#define pii pair< int,int >
#define pll pair< long long, long long >
#define pib pair< int,bool >
 
#define casenos printf("Case %d: ",tlc);
#define casenonl printf("Case %d:\n",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)
 
#define sfl(def_var) scanf("%lld",&def_var)
#define sfll(def_var,def_var2) scanf("%lld %lld",&def_var,&def_var2)
#define sflll(def_var,def_var2,def_var3) scanf("%lld %lld %lld",&def_var,&def_var2,&def_var3)
 
#define sfd(def_var) scanf("%lf",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfis(def_var) printf("%d ",def_var)
 
#define pfle(def_var) printf("%lld\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfls(def_var) printf("%lld ",def_var)
 
#define pfd(def_var) printf("%lf",def_var)
 
#define nl printf("\n");
 
#define casenownl output << "Case " << tlc << ":\n";
#define casenows output << "Case " << tlc << ": ";
 
#define READ        freopen("input.txt","r",stdin)
#define WRITE       freopen("output.txt","w",stdout)
#define BOOST       ios_base::sync_with_stdio(false);cin.tie(NULL)
 
int a,b,n,mod;
 
void multiply(int x[2][2],int y[2][2])
{
    int temp[2][2];
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            temp[r][c]=0;
            for(int s=0;s<2;s++)
            {
                temp[r][c]+=(x[r][s]*y[s][c])%mod;
                temp[r][c]%=mod;
            }
        }
    }
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            x[r][c]=temp[r][c];
        }
    }
 
}
 
 
void power(int M[2][2],int n)
{
    if(n==1) return;
 
    power(M,n/2);
 
    multiply(M,M);
 
    if(n&1)
    {
        int temp[2][2]={1,1,1,0}; //|1 1|
                                  //|1 0|
        multiply(M,temp);
    }
 
}
int f(int n)
{
    if(n==0) return a%mod;
    if(n==1) return b%mod;
 
    int F[2][2]={b,0,a,0}; //|f(n)  | = | b |
                           //|f(n-1)|   | a |
 
    int M[2][2]={1,1,1,0}; //|1 1|
                           //|1 0|
    n-=1;
    power(M,n);
 
    multiply(M,F);
    return M[0][0];
}
 
 
int main()
{
    int t,m;
    sfi(t);
    tloop(t)
    {
        sfii(a,b);
        sfii(n,m);
        mod=1;
        while(m--) mod*=10;
        casenos; pfie(f(n));
    }
}
 