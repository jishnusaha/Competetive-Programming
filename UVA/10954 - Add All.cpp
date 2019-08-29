#include<bits/stdc++.h>
using namespace std;

#define loop(i,n1) for(int l=i;l<=n1;l++)
#define pi acos(-1)
#define ll long long

int main()
{
    int n,i;
    while(cin >> n)
    {
        if(n==0) break;
        int a[n];
        loop(0,n-1)
        {
            cin >> a[l];
        }
        sort(a,a+n);

        ll sum=0,s;
        loop(1,n-1)
        {
            s=a[l]+a[l-1];
            sum+=s;
            a[l]=s;
            sort(a+l,a+n);
        }
        cout << sum << endl;
    }
}