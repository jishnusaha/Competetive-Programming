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
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfi(def_var) printf("%d",def_var)
#define pfin(def_var) printf("%d\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define pfs(def_var) printf("%s",def_var)
#define pfsn(def_var) printf("%s\n",def_var)
string place[20];
int w,h;
int a[20][20];
int c=0;
 
void dfs(int x,int y)
{
    a[x][y]=1;
    c++;
    if(x>0)
    {
        if(place[x-1][y]=='.' && a[x-1][y]==0)
        {
            dfs(x-1,y);
        }
    }
 
    if(x<h-1)
    {
        if(place[x+1][y]=='.' && a[x+1][y]==0)
        {
            dfs(x+1,y);
        }
    }
    if(y>0)
    {
        if(place[x][y-1]=='.' && a[x][y-1]==0)
        {
            dfs(x,y-1);
        }
    }
    if(y<w-1)
    {
        if(place[x][y+1]=='.' && a[x][y+1]==0)
        {
            dfs(x,y+1);
        }
    }
 
 
 
}
 
int main()
{
 
 
    int t;
    sfi(t);
    tloop(t)
    {
 
        sfii(w,h);
 
        loop(0,h-1) cin >> place[lc];
        int startX,startY;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j< place[i].size();j++)
            {
                if(place[i][j]=='@') { startX=i; startY=j; }
            }
        }
 
        loop(0,19)
        {
            loop2(0,19) a[lc][lc2]=0;
        }
        a[startX][startY]=1;
        c=0;
        dfs(startX,startY);
        caseno;
        pfin(c);
 
    }
}
 