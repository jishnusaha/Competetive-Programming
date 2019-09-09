#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double r,area;
    int T,i;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> r;
        area= r*r*4-r*r*2*acos(0);
        cout << "Case " << i << ": ";
        cout << fixed << setprecision(2) << area << endl;
    }
    return 0;
}
 