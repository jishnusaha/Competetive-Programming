#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define pi acos(-1)
#define ll long long

int main()
{
    int a[200],n,f,l;
    while(1)
    {
        cin >> n;
        if(n==0) break;
        if(n==1)
        {
            cout << "Discarded cards:\n";
            cout << "Remaining card: 1\n";
        }
        else if(n==2)
        {
            cout << "Discarded cards: 1\n";
            cout << "Remaining card: 2\n";
        }
        else
        {
            f=1;
            l=n;
            loop(f,n) a[l]=l;
            cout << "Discarded cards: " << a[f];
            f++;
            while(1)
            {
                if(n==f) break;
                a[n+1]=a[f];
                n++;
                f++;
                cout << ", " << a[f];
                f++;
            }
            cout << endl;
            cout << "Remaining card: " << a[n] << endl;

        }


    }
}