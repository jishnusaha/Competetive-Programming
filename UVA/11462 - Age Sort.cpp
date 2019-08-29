#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define ll long long

int main()
{
    int n;
    while(1)
    {
        cin >> n;
        if(n==0) break;
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        cout << a[0];
        for(int i=1;i<n;i++) printf(" %d",a[i]);
        cout << endl;
    }

}