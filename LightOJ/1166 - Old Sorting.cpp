#include<bits/stdc++.h>
using namespace std;
 
#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
 
int main()
{
    int n,i,j;
    int t;
    scanf("%d",&t);
    tloop(1,t)
    {
 
        scanf("%d",&n);
        int a[n+1];
        int p[n+1];
        p[0]=0;
 
        for(int l=1;l<=n;l++)
        {
            scanf("%d",&a[l]);
            p[a[l]]=l;
 
        }
        int s=0;
        loop(1,n)
        {
            if(p[l]!=l)
            {
                int tv=a[l],tp=p[l];
 
                swap(a[l],a[p[l]]);
                p[tv]=tp;
                s++;
            }
        }
        cout << "Case " << tl << ": " << s << endl;
    }
 
}