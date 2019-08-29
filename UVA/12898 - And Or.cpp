#include<bits/stdc++.h>

using namespace std;

int check(unsigned long long c)
{
    int r=0;
    while(c) {r++; c>>=1; }
    return r;

}
int main()
{
    int t,j,i;
    unsigned long long a,b,x,y,d;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> a >> b;
        int m=check(a);
        int n=check(b);
        if(a==b) {x=a; y=b;}
        else if(m==n)
        {
            d=a^b;
            int k=check(d);
            d=a;
            for(k--;k>=0;k--)
            {
                d&=~(1LL<<k);
            }
            y=d;

            d=a^b;
            k=check(d);
            d=a;
            for(k--;k>=0;k--)
            {
                d|=(1LL<<k);
            }
            x=d;
        }
        else
        {
            y=0;
            x=b;
            while(n--)
            {
                x=x|(1LL<<n);
            }
        }
        cout << "Case " << i << ": " << x << " " << y << endl;
    }
}