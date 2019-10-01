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
    int t,a,b;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> a >> b;
        int s=0,t=a;
        t%=3;
 
        if(t==0) s=1;
        else if(t==1)
        {
            a++;
            if(a<=b) {s++; a++;}
            if(a<=b) {s++;}
        }
        else
        {
            s=1;
            a++;
            if(a<=b) {s++;}
        }
        b-=a;
        s+=(b/3)*2;
        b%=3;
        if(b==2) s++;
        cout << "Case " << i << ": " << s << endl;
    }
}
 
