#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,r,n,i,j,h,l,mid,m,k;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> n;
        int a[n+1];
        a[0]=0;
        l=0;
        for( j=1;j<=n;j++)
        {
            scanf("%d",&a[j]);
            if( (a[j]-a[j-1]) > l ) l=a[j]-a[j-1];
        }
        h=1000000000;
        k=h;
        for(; l<=h ; )
        {
            mid=(h+l)/2;
            m=mid;
            for(j=1;j<=n;j++)
            {
                if(mid ==(a[j]-a[j-1])) mid--;
                else if(mid < (a[j]-a[j-1]) ) { break; }
            }
            if(j>n){ h=m-1; if(k>m) k=m; }
            else l=m+1;
 
        }
        cout << "Case " << i << ": " << k <<endl;
    }
}