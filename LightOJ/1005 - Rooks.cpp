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
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
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
 
bool row_taken[31],col_taken[31];
vector< pair<int,int> > store;
int n,k,c;
 
ll dp[33][1024];
ll find_ans(int row=1,int taken=0)
{
    if(taken==k)
    {
        return 1;
    }
    if(row>n ) return 0;
 
    if(dp[row][taken]>-1) return dp[row][taken];
    dp[row][taken]=0;
 
    for(int j=1;j<=n;j++)
    {
        if(!col_taken[j] && !row_taken[row])
        {
            col_taken[j]=row_taken[row]=true;
            store.push_back( make_pair(row,j) );
            dp[row][taken]+=find_ans(row+1,taken+1);
            store.pop_back();
            col_taken[j]=row_taken[row]=false;
        }
    }
    dp[row][taken]+=find_ans(row+1,taken);
    return dp[row][taken];
}
 
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        c=0;
        sfii(n,k);
        mem(dp,-1);
        caseno;cout << find_ans() << endl;;
 
    }
}
 