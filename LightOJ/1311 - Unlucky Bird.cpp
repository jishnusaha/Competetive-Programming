#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    int T;
    double t1,t2,d,b,v1,v2,v3,a1,a2;
    cin >> T;
    for(int i=1;i<=T;i++)
    {
         cin >> v1 >> v2 >> v3 >> a1 >> a2;
            d=(v1*v1/a1+v2*v2/a2)/2;
            t1=v1/a1;
            t2=v2/a2;
            if(t1>t2) b=v3*t1;
            else b=v3*t2;
            cout << "Case " << i << ": ";
            cout << fixed << setprecision(10) << d << " " << b << endl;
    }
}