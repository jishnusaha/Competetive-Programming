#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define pi acos(-1)
#define ll long long


int main()
{
    int n,c;
    while(cin >> n)
    {
        int ans[n],a[n];
        memset(ans,0,sizeof(ans));
        cin >> a[0];
        loop(1,n-1)
        {
            cin >> a[l];
            c=abs(a[l]-a[l-1]);
            ans[c]=1;
        }
        bool r=true;
        loop(1,n-1)
        {
            if(ans[l]==0)
            {
                r=false;
                break;
            }
        }
        if(r) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }

}