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

#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
#define BOOST		ios_base::sync_with_stdio(false);cin.tie(NULL)

//    sample matrix showing for d=4
//
//      |a1 a2 a3 a4|
//      |1  0  0  0 |
//    M=|0  1  0  0 |
//      |0  0  1  0 |
//
//      |F(n)  |
//      |F(n-1)|
//    A=|F(n-2)|
//      |F(n-3)|
//
//      |F(n+1)|
//      |F(n)  |
//    B=|F(n-1)|
//      |F(n-2)|
//
//    M*A=B



ll mod,d,Org_M[20][20],Org_F[20][20]; // although we need M matrix d*d and F matrix d*1
                                      // but for calculation simplicity we will use 20*20 matrix for both


void multiply(ll M[20][20],ll F[20][20])
{
    //although we took the matrix by 20*20, but we know we only need d*d and we will work on only d*d

    ll result[d][d];

    for(int r=0;r<d;r++)
    {
        for(int c=0;c<d;c++)
        {
            result[r][c]=0;
            for(int s=0;s<d;s++)
            {
                result[r][c]+=(M[r][s]*F[s][c])%mod;;
                result[r][c]%=mod;
            }
        }
    }
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            M[i][j]=result[i][j];
        }
    }
}

void power(ll M[20][20],int n)
{
    if(n==1) return;
    power(M,n/2);
    multiply(M,M);

    if(n&1)
    {
        ll temp[20][20];
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                temp[i][j]=Org_M[i][j];
            }
        }
        multiply(M,temp);
    }
}


int fibonacci(int n)
{
    if(n<=d) return Org_F[0][n-1]%mod;

    ll F[20][20];
    ll M[20][20];
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            M[i][j]=Org_M[i][j];
            F[i][j]=Org_F[i][j];
        }
    }

    power(M,n-d);
    multiply(M,F);

    return M[0][0];
}

int main()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            Org_M[i][j]=0;
            Org_F[i][j]=0;
            if(i>0 && i==j) Org_M[i][j-1]=1;
        }
    }
    int n;

    while(cin >> d >> n >> mod)
    {
        if(d==0 && n==0 && mod==0) break;
        loop(0,d-1) cin >> Org_M[0][lc];
        bloop(d-1,0) cin >> Org_F[blc][0];
        pfie(fibonacci(n));
    }
}
