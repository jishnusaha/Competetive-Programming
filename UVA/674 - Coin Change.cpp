#include <bits/stdc++.h>

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

#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");


int a[5]={50, 25, 10, 5,1};
int n;
int dp[5][7490];
int solve(int i=0,int amount=0)
{
    //cout << "called : i : " << i << ". amount : " << amount << endl;
    if(i==5)
    {
        if(amount==0)
        {
            //cout << "return : " << 1 << endl;
            //dp[i][amount]=1;
            return 1;
        }
        else
        {
            //dp[i][amount]=1;
            return 0;
        }
    }
    if(dp[i][amount]!=-1)
    {
        //cout << "saved. return : " << dp[i][amount] << endl;
        return dp[i][amount];
    }
    int res1=0,res2=0;
    if(amount- a[i]>=0)
    {
        res1=solve(i,amount-a[i]);
    }
    res2=solve(i+1,amount);
    //return res1+res2;
    dp[i][amount]= res1+res2;
    return dp[i][amount];

}
int main()
{
    for(int i=0;i<7490;i++)
    {
        for(int j=0;j<5;j++) dp[j][i]=-1;
    }

    while(cin >> n)
    {
        cout << solve(0,n) << endl;
    }
}