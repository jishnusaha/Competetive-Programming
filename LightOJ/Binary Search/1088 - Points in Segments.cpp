#include<cstdio>
#include <iostream>
using namespace std;
int main()
{
    int t,i,n,q,j,k1,k2,l_i,h,l,m;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        //cout << "Case " << i << ":\n";
        scanf("%d %d",&n,&q);
        //cin >> n >> q;
        int a[n];
        for(j=0;j<n;j++) scanf("%d",&a[j]);
            //cin >> a[j];
        printf("Case %d:\n",i);
        while(q--)
        {
            scanf("%d %d",&k1,&k2);
            //cin >> k1 >> k2;
            h=n-1,l=0;
            while(l<=h) //lower bound of k1
            {
                m=(h+l)/2;
                if(a[m]==k1 || k1 < a[m]) h=m-1;
                else l=m+1;
            }
            l_i=l;
            h=n-1;
            l=0;
            while(l<=h) //upper bound of k2
            {
                m=(h+l)/2;
                if(a[m]==k2 || k2>a[m]) l=m+1;
                else h=m-1;
            }
            //l_i=l-l_i;
            printf("%d\n",l-l_i);
            //cout << l-l_i << endl;
        }
    }
}