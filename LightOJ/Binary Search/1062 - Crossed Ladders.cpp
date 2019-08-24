#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ///draw that figure in graph where,
    /// y's starting will be (0,0) point last will be (mid,r)
    ///x's starting (0,p) point last will be (mid,0)
    ///intersection point will be (q,c)
 
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        double x,y,c;
        cin >> x >> y >> c;
        double low=0.1,high=x;
        double mid=(low+high)/2;
        while(low<=high)
        {
            //cout << "low : " << low << " high : " << high << " mid : " << mid << endl;
            double p=sqrt(x*x-mid*mid);
            double r=sqrt(y*y-mid*mid);
            double m1=-(p/mid); ///slope of x
            double m2=r/mid; ///slope of y
            double q=c/m2; ///y=m12*x+c equation of y
            double cc=m1*q+p; ///now, calculation c from y=-m1*x+c equation of x
            if(abs(cc-c)<0.000000001) break;
            if(cc>c) low=mid-0.0000001;
            else high=mid+0.0000001;
            mid=(low+high)/2;
        }
        cout << "Case " << i << ": " << fixed << setprecision(9) << mid << endl;
    }
 
}