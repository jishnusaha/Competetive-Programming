/*
    count the time need to go home for a,b and c
    maximum count will be ans
*/
 
 
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
#define casenos printf("Case %d: ",tlc);
#define casenonl printf("Case %d:\n",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfis(def_var) printf("%d ",def_var)
 
#define pfle(def_var) printf("%lld\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfls(def_var) printf("%lld ",def_var)
 
#define pfd(def_var) printf("%lf",def_var)
 
#define nl printf("\n");
 
int n,m;
string grid[22];
bool pushed[22][22];
int bfs(int src_i,int src_j)
{
    mem(pushed,0);
    pushed[src_i][src_j]=true;
    queue< pair< pair<int,int>,int > >q;
    q.push( make_pair( make_pair(src_i,src_j),0) );
    while(!q.empty())
    {
        int i=q.front().first.first;
        int j=q.front().first.second;
        int cost=q.front().second;
        q.pop();
        if(i>0)
        {
 
            if(grid[i-1][j]!='#' && grid[i-1][j]!='m')
            {
                if(!pushed[i-1][j])
                {
                    if(grid[i-1][j]=='h') return cost+1;
 
                    pushed[i-1][j]=true;
                    q.push( make_pair( make_pair(i-1,j),cost+1  )  );
                }
            }
        }
        if(i<n-1)
        {
 
            if(grid[i+1][j]!='#' && grid[i+1][j]!='m')
            {
                if(!pushed[i+1][j])
                {
                    if(grid[i+1][j]=='h') return cost+1;
 
                    pushed[i+1][j]=true;
                    q.push( make_pair( make_pair(i+1,j),cost+1  )  );
                }
            }
        }
        if(j>0)
        {
 
            if(grid[i][j-1]!='#' && grid[i][j-1]!='m')
            {
                if(!pushed[i][j-1])
                {
                    if(grid[i][j-1]=='h') return cost+1;
 
                    pushed[i][j-1]=true;
                    q.push( make_pair( make_pair(i,j-1),cost+1  )  );
                }
            }
        }
        if(j<m-1)
        {
 
            if(grid[i][j+1]!='#' && grid[i][j+1]!='m')
            {
                if(!pushed[i][j+1])
                {
                    if(grid[i][j+1]=='h') return cost+1;
 
                    pushed[i][j+1]=true;
                    q.push( make_pair( make_pair(i,j+1),cost+1  )  );
                }
            }
        }
    }
 
}
 
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        sfii(n,m);
        loop(0,n-1) cin >> grid[lc];
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='a' || grid[i][j]=='b' || grid[i][j]=='c')
                {
                    ans=max(ans,bfs(i,j));
                }
            }
        }
        casenos; pfie(ans);
    }
}