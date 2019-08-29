#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        double c,d;
        cin >>c >> d;
        double f=9*c/5+32+d;
        c=(f-32)*5/9;
        cout << "Case " << i << ": " << fixed << setprecision(2) << c << endl;
    }

}
