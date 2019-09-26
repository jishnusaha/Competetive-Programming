
 
#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(il,nl) for(int l=il;l<=nl;l++)
#define loop2(il2,nl2) for(int l2=il2;l2<=nl2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
#define tloop(tll,nt) for(int tl=tll;tl<=nt;tl++)
#define caseno printf("Case %d: ",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
 
 
int main()
{
 
 
 
    int t,r,c,res;
    scanf("%d",&t);
    tloop(1,t)
    {
        scanf("%d %d",&r,&c);
        if(r==1) res=c;
        else if(c==1) res=r;
        else if(r==2)
        {
            if(c<=4) res=4;
            else if(c%4==0) res=(c/4)*4;
            else if(c%4==1) res=(c/4)*4+2;
            else  res=(c/4)*4+4;
 
        }
        else if(c==2)
        {
            if(r<=4) res=4;
            else if(r%4==0) res=(r/4)*4;
            else if(r%4==1) res=(r/4)*4+2;
            else  res=(r/4)*4+4;
 
        }
        else if(r&1) ///odd row
        {
            if(c&1) res=(r/2)*c+c/2+1;
            else res=(r/2)*c+c/2;
        }
        else
        {
            if(c&1) res=(r/2)*c;
            else res=(r/2)*c;
        }
        caseno; printf("%d\n",res);
    }
}