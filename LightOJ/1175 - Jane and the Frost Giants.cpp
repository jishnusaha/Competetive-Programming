/*
    idea:
        first, for all position, using bfs/dfs  count the time of fire reaching for every position. if, there are multiple fire,then the fire will reach different position
        in different time. so, for a position we will  assign the smallest count among every fire.
       
        then we will run bfs/dfs for jane, where jane will move to a position where there is  no obstacle and no fire reached before her.
        if a fire reached to a position before jane, then that position's value will be less then jane traverse count.
 
 
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
 
int dot=-1,obstacle=-2,fire=0;
 
string s[210];
int r,c;
pair<int,int>jane_pos;
int grid[210][210];
 
bool pushed[210][210];
 
 
struct queue_data{
    int row,col,time;
 
};
 
bool possible;
int cost;
 
void bfs_jane(pair<int,int> source)
{
    queue<queue_data> q;
    queue_data u,v;
    u.row=source.first,u.col=source.second,u.time=0;
    q.push(u);
    pushed[source.first][source.second]=true;
 
    while(!q.empty())
    {
        u=q.front();
        q.pop();
 
        if(u.col==c-1 || u.col==0 || u.row==0 || u.row==r-1)
        {
            cost=min(cost,u.time+1);
            possible=true;
        }
 
        if( grid[u.row][u.col-1]!=obstacle && grid[u.row][u.col-1]!=fire && (grid[u.row][u.col-1]>u.time+1 || grid[u.row][u.col-1]==dot)   && !pushed[u.row][u.col-1])
        {
            pushed[u.row][u.col-1]=true;
            v.col=u.col-1,v.row=u.row,v.time=u.time+1;
            q.push(v);
        }
        if( grid[u.row][u.col+1]!=obstacle && grid[u.row][u.col+1]!=fire && (grid[u.row][u.col+1]>u.time+1 || grid[u.row][u.col+1]==dot)  && !pushed[u.row][u.col+1])
        {
            pushed[u.row][u.col+1]=true;
            v.col=u.col+1,v.row=u.row,v.time=u.time+1;
            q.push(v);
        }
        if(grid[u.row-1][u.col]!=obstacle && grid[u.row-1][u.col]!=fire && (grid[u.row-1][u.col]>u.time+1 || grid[u.row-1][u.col]==dot)  && !pushed[u.row-1][u.col])
        {
            pushed[u.row-1][u.col]=true;
            v.col=u.col,v.row=u.row-1,v.time=u.time+1;
            q.push(v);
        }
        if( grid[u.row+1][u.col]!=obstacle && grid[u.row+1][u.col]!=fire && (grid[u.row+1][u.col]>u.time+1 || grid[u.row+1][u.col]==dot)  && !pushed[u.row+1][u.col])
        {
            pushed[u.row+1][u.col]=true;
            v.col=u.col,v.row=u.row+1,v.time=u.time+1;
            q.push(v);
        }
    }
 
}
 
 
void bfs_fire(pair<int,int> source)
{
    queue< queue_data > q;
    queue_data u,v;
    u.row=source.first,u.col=source.second,u.time=0;
    q.push(u);
 
    pushed[source.first][source.second]=true;
 
    while(!q.empty())
    {
        u=q.front();
 
        grid[u.row][u.col]=u.time;
        q.pop();
        if(u.col>0)
        {
 
            if(grid[u.row][u.col-1]!=obstacle && !pushed[u.row][u.col-1] )
            {
                v.row=u.row,v.col=u.col-1,v.time=u.time+1;
                if( grid[v.row][v.col] > v.time || grid[v.row][v.col]==dot )
                {
                    grid[v.row][v.col] = v.time;
                    q.push(v);
                    pushed[v.row][v.col]=true;
                }
            }
        }
        if(u.col<c-1)
        {
            if(grid[u.row][u.col+1]!=obstacle &&  !pushed[u.row][u.col+1] )
            {
                v.row=u.row,v.col=u.col+1,v.time=u.time+1;
                if( grid[v.row][v.col] > v.time || grid[v.row][v.col]==dot )
                {
                    grid[v.row][v.col] = v.time;
                    q.push(v);
                    pushed[u.row][u.col+1]=true;
                }
            }
        }
 
        if(u.row>0)
        {
            if(grid[u.row-1][u.col]!=obstacle && !pushed[u.row-1][u.col] )
            {
                v.row=u.row-1,v.col=u.col,v.time=u.time+1;
                if( grid[v.row][v.col] > v.time || grid[v.row][v.col]==dot)
                {
                    grid[v.row][v.col] = v.time;
                    q.push(v);
                    pushed[v.row][v.col]=true;
                }
            }
        }
        if(u.row<r-1)
        {
            if(grid[u.row+1][u.col]!=obstacle && !pushed[u.row+1][u.col] )
            {
                v.row=u.row+1,v.col=u.col,v.time=u.time+1;
                if( grid[v.row][v.col] > v.time || grid[v.row][v.col]==dot)
                {
                    grid[v.row][v.col] = v.time;
                    q.push(v);
                    pushed[v.row][v.col]=true;
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
        sfii(r,c);
        loop(0,r-1)
        {
            cin >> s[lc];
        }
 
        vector< pair<int,int> >fire_pos;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<s[i].size();j++)
            {
                if(s[i][j]=='J')
                {
                    jane_pos=make_pair(i,j);
                }
                else if(s[i][j]=='#')
                {
                    grid[i][j]=obstacle;
                }
                else if(s[i][j]=='.')
                {
                    grid[i][j]=dot;
                }
                else
                {
                    fire_pos.push_back( make_pair(i,j) );
                    grid[i][j]=fire;
                }
            }
        }
        for(int lc=0;lc<fire_pos.size();lc++)
        {
            mem(pushed,0);
            bfs_fire(fire_pos[lc]);
        }
 
        possible=false;
        cost=INT_MAX;
        mem(pushed,0);
        bfs_jane(jane_pos);
        caseno;
        if(possible) pfie(cost);
        else printf("IMPOSSIBLE\n");
    }
}
 