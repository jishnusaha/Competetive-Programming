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
    cin >> t;
    ll s,x,y;
    for(int i=1;i<=t;i++)
    {
        cin >> s;
        double rd=sqrt(s);
        ll ri=rd;
        if(ri==rd)
        {
            if(ri&1) {x=1;y=ri;}
            else {x=ri; y=1;}
        }
        else
        {
            ll r1=(ri+1)*(ri+1);
            ll r2=ri*ri+1;
            ll mid=(r1+r2)/2;
            if(mid==s) {x=ri+1; y=ri+1;}
            else if(mid>s)
            {
                if(ri&1)
                {
                    y=ri+1;
                    x=y-(mid-s);
                }
                else
                {
                    x=ri+1;
                    y=x-(mid-s);
                }
            }
            else
            {
                if(ri&1)
                {
                    x=ri+1;
                    y=x-(s-mid);
                }
                else
                {
                    y=ri+1;
                    x=y-(s-mid);
                }
            }
        }
        cout << "Case " << i << ": " << x << ' ' << y << endl;
    }
}