/*
    problem confusion:
                we must take letters in alphabetic serial
                here, we must take letter if we go through that position
                so,for example, while going for C we can not go through any other letters greater then C (such as D,E,F) as, they are not taken till now
               
                then, if we take one letter then that position will be free that means we can go through that position for later bigger letter's  searching.
               
    idea:
        simple dfs or bfs algorithm
 
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
#define caseno printf("Case %d: ",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
 
 
int n;
string grid[15];
 
bool found;
int cost;
char target;
bool pushed[15][15];
 
struct queue_data{
    int row,coll,cost;
};
 
void bfs(pair<int,int>source)
{
    queue_data u,v;
    queue< queue_data >q;
    u.cost=0,u.row=source.first,u.coll=source.second;
    q.push(u);
    pushed[source.first][source.second]=true;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
 
        if(grid[u.row][u.coll]==target)
        {
            found=true;
            cost=u.cost;
            grid[u.row][u.coll]='.'; ///this position will be free now
            return ; ///returning because bfs traverse level by level.
                     ///and if this node is found then the path covered
                     ///to reach that node will be shortest as path weight is same
        }
 
        if(u.coll>0)
        {
            if( (grid[u.row][u.coll-1]==target || grid[u.row][u.coll-1]=='.') && !pushed[u.row][u.coll-1])
            {
                v.coll=u.coll-1,v.row=u.row,v.cost=u.cost+1;
                pushed[v.row][v.coll]=true;
                q.push(v);
            }
        }
 
        if(u.coll<n-1)
        {
            if(  (grid[u.row][u.coll+1]==target || grid[u.row][u.coll+1]=='.') && !pushed[u.row][u.coll+1])
            {
                v.coll=u.coll+1,v.row=u.row,v.cost=u.cost+1;
                pushed[v.row][v.coll]=true;
                q.push(v);
            }
        }
        if(u.row>0)
        {
            if((grid[u.row-1][u.coll]==target || grid[u.row-1][u.coll]=='.') && !pushed[u.row-1][u.coll])
            {
                v.coll=u.coll,v.row=u.row-1,v.cost=u.cost+1;
                pushed[v.row][v.coll]=true;
                q.push(v);
            }
        }
 
        if(u.row<n-1)
        {
            if( (grid[u.row+1][u.coll]==target || grid[u.row+1][u.coll]=='.') && !pushed[u.row+1][u.coll])
            {
                v.coll=u.coll,v.row=u.row+1,v.cost=u.cost+1;
                pushed[v.row][v.coll]=true;
                q.push(v);
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
        sfi(n);
        pair< int,int > latter[26];
        loop(0,n-1) cin >> grid[lc];
        int latters=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( grid[i][j]>='A' && grid[i][j]<='Z'  )
                {
                    int p=(int)(grid[i][j]-'A');
                    latter[p]=make_pair(i,j);
                    latters++;
                }
            }
        }
       
        found=true;
        int ans=0;
        grid[latter[0].first][latter[0].second ]='.';
        for(int i=1;i<latters;i++)
        {
            found=false;
            cost=INT_MAX;
            target=char('A'+i );
            mem(pushed,0);
            bfs(latter[i-1]);
            if(found) ans+=cost;
            else break;
        }
        caseno;
        if(found) pfie(ans);
        else printf("Impossible\n");
    }
}