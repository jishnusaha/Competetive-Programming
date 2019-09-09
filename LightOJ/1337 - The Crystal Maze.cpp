/*
    idea:
        run bfs from unvisited empty place.
        then count which place can be visited from that empty place
        and count how many crystal found during that visit.
        think to be understand that, in one bfs call lets say
        we start from 1, and then visited 2 3 5, so, in case
        we start visit from 3 we will visit 1,2,5.
       
        so, if we get a 10 amount of crystal  for a bfs from starting 1, we will get exactly that amount (10) of crystal
        if we start from 2, 3 of 5.
       
        so we can assign 10 for 1, 2,3,5. not need to calculate for 2,3 of 5 again.
 
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
 
#define pii pair< int,int >
#define pll pair< long long, long long >
#define pib pair< int,bool >
 
#define casenos printf("Case #%d: ",tlc);
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
#define writefile ofstream output; output.open("output.txt");
 
 
int r,c;
 
string grid[510];
bool visit[510][510];
int ans[510][510];
vector< pair<int,int> > revealed;
int cnt;
 
void bfs(int i,int j)
{
    queue< pair<int,int> >q;
    q.push({i,j});
    revealed.pb({i,j});
    visit[i][j]=true;
    if(grid[i][j]=='C') cnt++;
    while(!q.empty())
    {
        int u_i=q.front().first;
        int u_j=q.front().second;
        q.pop();
 
        if(u_j<c-1)
        {
            if(!visit[u_i][u_j+1])
            {
                if(grid[u_i][u_j+1]=='C') cnt++;
                if(grid[u_i][u_j+1]=='C' || grid[u_i][u_j+1]=='.')
                {
                    revealed.pb( {u_i,u_j+1} );
                    q.push({u_i,u_j+1});
                    visit[u_i][u_j+1]=true;
                }
            }
        }
        if(u_j>0)
        {
            if(!visit[u_i][u_j-1])
            {
                if(grid[u_i][u_j-1]=='C') cnt++;
                if(grid[u_i][u_j-1]=='C' || grid[u_i][u_j-1]=='.')
                {
                    revealed.pb( {u_i,u_j-1} );
                    q.push({u_i,u_j-1});
                    visit[u_i][u_j-1]=true;
                }
            }
        }
 
 
 
        if(u_i<r-1)
        {
            if(!visit[u_i+1][u_j])
            {
                if(grid[u_i+1][u_j]=='C') cnt++;
                if(grid[u_i+1][u_j]=='C' || grid[u_i+1][u_j]=='.')
                {
                    revealed.pb( {u_i+1,u_j} );
                    q.push({u_i+1,u_j});
                    visit[u_i+1][u_j]=true;
                }
            }
        }
        if(u_i>0)
        {
            if(!visit[u_i-1][u_j])
            {
                if(grid[u_i-1][u_j]=='C') cnt++;
                if(grid[u_i-1][u_j]=='C' || grid[u_i-1][u_j]=='.')
                {
                    revealed.pb( {u_i-1,u_j} );
                    q.push({u_i-1,u_j});
                    visit[u_i-1][u_j]=true;
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
        int q;
        sfiii(r,c,q);
        loop(0,r-1) cin >> grid[lc];
        mem(visit,false);
 
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!visit[i][j] && grid[i][j]=='.')
                {
                    revealed.clear();
                    cnt=0;
                    bfs(i,j);
                    for(int i=0;i<revealed.size();i++)
                    {
                        ans[revealed[i].first ][revealed[i].second ]=cnt;
                    }
                }
            }
        }
        casenonl;
        while(q--)
        {
            sfii(r,c);
            pfie(ans[r-1][c-1]);
        }
    }
}
 