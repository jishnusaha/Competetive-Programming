#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int d=sqrt(n);
        int s=0;
        loop(1,d)
        {
            if(n%l==0)
            {
                int r=n/l;
                if(l%k)
                {
                    s+=l;

                }
                if(r!=l && r%k)
                {
                    s+=r;
                }
            }
        }
        printf("%d\n",s);
    }
}