#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define loop2(i3,n3) for(int l3=i3;l3<=n3;l3++)
#define pi acos(-1)
#define ll long long

int main()
{
    int n,i,j,a,f;
    cin >> n;
    loop(1,n)
    {
        if(l>1) cout << endl;
        cin >> a >> f;
        for(int l2=1;l2<=f;l2++)
        {
            if(l2>1) cout << endl;
            for(i=1;i<=a;i++)
            {
                for(j=1;j<=i;j++)
                    cout << i;
                cout << endl;
            }
            for(i=a-1;i>0;i--)
            {
                for(j=1;j<=i;j++)
                    cout << i;
                cout << endl;
            }
        }
    }
}