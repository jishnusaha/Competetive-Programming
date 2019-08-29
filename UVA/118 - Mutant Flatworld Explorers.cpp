#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define il() while(1)
#define pi acos(-1)
#define ll long long

int main()
{

    int n,i,j,gridx,gridy;
    scanf("%d %d",&gridx,&gridy);
    int grid[gridx+1][gridy+1];
    loop(0,gridx)
    {
        loop2(0,gridy)
        {
            grid[l][l2]=0;
        }

    }
    int x,y;
    char c;
    string s;
    while(scanf("%d %d %c",&x,&y,&c)!=EOF)
    {
        bool x_dec=false,x_inc=false,y_dec=false,y_inc=false,lost=false;
        if(c=='N') y_inc=true;
        else if(c=='S') y_dec=true;
        else if(c=='E') x_inc=true;
        else if(c=='W') x_dec=true;
        cin.ignore();
        getline(cin,s);
        loop(0,s.size()-1)
        {
            if(s[l]=='L')
            {
                if(x_dec) {x_dec=false; y_dec=true; }
                else if(x_inc) {x_inc=false; y_inc=true; }
                else if(y_dec) {y_dec=false; x_inc=true; }
                else if(y_inc) {y_inc=false; x_dec=true; }
            }
            else if(s[l]=='R')
            {
                if(x_dec) {x_dec=false; y_inc=true; }
                else if(x_inc) {x_inc=false; y_dec=true; }
                else if(y_dec) {y_dec=false; x_dec=true; }
                else if(y_inc) {y_inc=false; x_inc=true; }
            }
            else
            {
                if(x_dec)
                {
                    if(x==0 && grid[x][y]==0 )
                    {
                        grid[x][y]=1;
                        lost=true;
                        break;
                    }
                    else if(x>0) x--;
                }
                else if(x_inc)
                {
                    if(x==gridx && grid[x][y]==0 )
                    {
                        grid[x][y]=1;
                        lost=true;
                        break;
                    }
                    else if(x<gridx) x++;
                }
                else if(y_dec)
                {
                    if(y==0 && grid[x][y]==0 )
                    {
                        grid[x][y]=1;
                        lost=true;
                        break;
                    }
                    else if(y>0) y--;
                }
                else if(y_inc)
                {
                    if(y==gridy && grid[x][y]==0 )
                    {
                        grid[x][y]=1;
                        lost=true;
                        break;
                    }
                    else if(y<gridy) y++;
                }
            }
        }
        cout << x << ' ' << y << ' ';
        if(y_inc) cout << 'N';
        else if(y_dec) cout << 'S';
        else if(x_inc) cout << 'E';
        else if(x_dec) cout << 'W';
        if(lost) cout << " LOST";
        cout << endl;
    }

}