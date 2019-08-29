#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        double d,l;
        cin >> d >> l;
        double b=d/2+(l-d)/2;
        double a=sqrt( (l/2)*(l/2)- (d/2)*(d/2)  );
        double area=acos(-1)*a*b;
        cout << fixed << setprecision(3) << area<< endl;
    }
}