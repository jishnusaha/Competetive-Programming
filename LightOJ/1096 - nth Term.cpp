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

int a,b,c,n,mod=10007;

int org_M[4][4]={a,0,b,1,1,0,0,0,0,1,0,0,0,0,0,1};
int F[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,c,0,0,0};

void multiply(int x[4][4],int y[4][4])
{

    int matrix_size=4;
    ll result[matrix_size][matrix_size];


    for(int r=0;r<matrix_size;r++)
    {
        for(int c=0;c<matrix_size;c++)
        {
            result[r][c]=0;
            for(int s=0;s<matrix_size;s++)
            {
                result[r][c]+=(x[r][s]*y[s][c])%mod;
                result[r][c]%=mod;
            }
        }
    }
    for(int i=0;i<matrix_size;i++)
    {
        for(int j=0;j<matrix_size;j++)
        {
            x[i][j]=result[i][j];
        }
    }
}



void power(int M[4][4],int n)
{
    if(n==1) return;

    power(M,n/2);

    multiply(M,M);

    if(n&1)
    {
        int temp[4][4];
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++) temp[i][j]=org_M[i][j];
        }

        multiply(M,temp);
    }

}
int f(int n)
{
    if(n<=2) return 0;

    n-=2;
    int M[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++) M[i][j]=org_M[i][j];
    }
    power(M,n);

    multiply(M,F);

    return M[0][0];
}


int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        sfi(n);
        sfiii(org_M[0][0],org_M[0][2],F[3][0]);
        casenos; pfie(f(n));
    }
}
