#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int l=i;l<=n;l++)
#define tloop(tn) for(int tl=1;tl<=tn;tl++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define rad_to_deg(angl) ((180*angl)/pi)
#define ll long long
#define caseno printf("Case %d: ",tl);
 
 
int main()
{
    int t;
    cin >> t;
    tloop(t)
    {
 
 
        int k;
        cin >> k;
        int ans,a[k*2];
 
        for(int i=0;i<2*k;i++)
        {
            cin >> a[i];
        }
        ans=a[1]-a[0]-1;
        for(int i=2;i<2*k;i+=2)
        {
            ans^=(a[i+1]-a[i]-1);
        }
 
        caseno;
 
        if(ans) cout << "Alice\n";
        else cout << "Bob\n";
    }
 
}
 