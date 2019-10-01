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


//  | a1 b1 c1 0  0  0  |   | f(n-1) |    | f(n)   |
//  | 1  0  0  0  0  0  |   | f(n-2) |    | f(n-1) |
//  | 0  0  0  0  1  0  |   | g(n-3) |    | f(n-2) |
//  | 0  0  0  a2 b2 c2 | * | g(n-1) | =  | g(n)   |
//  | 0  0  0  1  0  0  |   | g(n-2) |    | g(n-1) |
//  | 0  1  0  0  0  0  |   | f(n-3) |    | f(n-2) |


///we will use this in our matrix

//  | a1 b1 c1 0  0  0  |   | f(2) |    | f(3) |
//  | 1  0  0  0  0  0  |   | f(1) |    | f(2) |
//  | 0  0  0  0  1  0  |   | g(0) |    | f(1) |
//  | 0  0  0  a2 b2 c2 | * | g(2) | =  | g(3) |
//  | 0  0  0  1  0  0  |   | g(1) |    | g(2) |
//  | 0  1  0  0  0  0  |   | f(0) |    | f(1) |


int a1,b1,c1,a2,b2,c2;
int f1,f2,f0;
int g1,g2,g0;

int Org_M[6][6]={
    a1,b1,c1, 0, 0, 0,
     1, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 1, 0,
     0, 0, 0, a2,b2,c2,
     0, 0, 0, 1, 0, 0,
     0, 1, 0, 0, 0, 0
     };

///although we need F matrix a column matrix but for calculation simplicity we are using it as a square matrix 6*6
int F[6][6]={
    f2,0,0,0,0,0,
    f1,0,0,0,0,0,
    g0,0,0,0,0,0,
    g2,0,0,0,0,0,
    g1,0,0,0,0,0,
    f0,0,0,0,0,0,
    };
int mod,fn,gn;

void multiply(int X[6][6],int Y[6][6])
{
    int result[6][6];
    for(int r=0;r<6;r++)
    {
        for(int c=0;c<6;c++)
        {
            result[r][c]=0;
            for(int s=0;s<6;s++)
            {
                result[r][c]+=(X[r][s]*Y[s][c])%mod;
                result[r][c]%=mod;
            }
        }
    }
    for(int r=0;r<6;r++)
    {
        for(int c=0;c<6;c++)
        {
            X[r][c]=result[r][c];
        }
    }

}

void power(int M[6][6],int n)
{
    if(n==1) return;
    power(M,n/2);
    multiply(M,M);

    if(n&1)
    {
        int temp[6][6];
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                temp[i][j]=Org_M[i][j];
            }
        }
        multiply(M,temp);
    }
}

void solve(int n)
{
    if(n<=2)
    {
        if(n==0)
        {
            gn=F[2][0]%mod;
            fn=F[5][0]%mod;
        }
        if(n==1)
        {
            gn=F[4][0]%mod;
            fn=F[1][0]%mod;
        }
        if(n==2)
        {
            gn=F[3][0]%mod;
            fn=F[0][0]%mod;
        }
        return;
    }

    int M[6][6];
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            M[i][j]=Org_M[i][j];
        }
    }
    power(M,n-2);

    multiply(M,F);
    fn=M[0][0];
    gn=M[3][0];

}

int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        sfiii(Org_M[0][0],Org_M[0][1],Org_M[0][2]);
        sfiii(Org_M[3][3],Org_M[3][4],Org_M[3][5]);
        sfiii(F[5][0],F[1][0],F[0][0]);
        sfiii(F[2][0],F[4][0],F[3][0]);
        sfi(mod);
        casenonl;
        int q,n;
        sfi(q);
        while(q--)
        {
            sfi(n);
            solve(n);
            pfis(fn); pfie(gn);
        }
    }
}
