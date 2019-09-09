#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long T,i,area,Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
        Dx=Cx+Ax-Bx;
        Dy=Cy+Ay-By;
        area=(Ax-Bx)*(By-Cy)-(Ay-By)*(Bx-Cx);
        area=abs(area);
        cout << "Case " << i << ": " << Dx << " " << Dy << " " << area << endl;
    }
}