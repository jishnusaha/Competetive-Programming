#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define pi acos(-1)
#define ll long long

int a[10004];
int main()
{
    int x,i=0;
    while(cin >> x)
    {
        i++;
        a[i]=x;
        sort(a,a+i+1);

        //for(int j=1;j<=i;j++) cout << a[j] << ' ';
        //cout << endl;
        if(i&1)
        {
            cout <<  a[i/2+1] << endl;
        }
        else
        {
            //cout << a[i/2] << " " << a[i/2+1] << endl;
            cout <<  (a[i/2]+a[i/2+1])/2 << endl;
        }

    }
}