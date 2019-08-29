#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define loop2(i3,n3) for(int l3=i3;l3<=n3;l3++)
#define pi acos(-1)
#define ll long long
int a[5002];
int r[10];
int check(int i)
{
    memset(r,0,sizeof(r));
    int k;

}
int main()
{
    int x,p,j;
    for(int i=1;i<=5000;i++)
    {
        p=i;
        memset(r,0,sizeof(r));
        while(p)
        {
            x=p%10;
            r[x]++;
            p/=10;
        }
        for(j=0;j<10;j++)
        {
            if(r[j]>1)
            {
                a[i]=1;
                break;
            }
        }
    }
    int n,m;
    while(cin >> n >>m)
    {
        int c=0;
        loop(n,m)
        {
            if(a[l]==0) c++;
        }
        cout << c << endl;
    }



}