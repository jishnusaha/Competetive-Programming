#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        double a,b,c,d;
        cin >> a >> b >> c >> d;
        double base;
        if(a>c) base=a-c;
        else base=c-a;
        double s=(b+d+base)/2;
        double area=sqrt( s*(s-b)*(s-d)*(s-base));
        double h=2*area/base;
 
        double trapi_area=0.5*(a+c)*h;
        cout << "Case " << i << ": " << fixed << setprecision(9) << trapi_area << endl;
    }
}
 
