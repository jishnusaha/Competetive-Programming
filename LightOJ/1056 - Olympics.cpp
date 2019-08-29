#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(il,nl) for(int l=il;l<=nl;l++)
#define loop2(il2,nl2) for(int l2=il2;l2<=nl2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define tloop(tll,nt) for(int tl=tll;tl<=nt;tl++)
#define il() while(1)
 
#define pi acos(-1)
#define ll long long
#define caseno printf("Case %d: ",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
 
int main()
{
    int t;
    cin >> t;
    tloop(1,t)
    {
        int x,y;
        char c;
        cin >> x >> c >> y;
        ///ay=bx
        double h=400,l=0.000000001,b,a,radius,angle,circle_slice;
        double perimeter;
        while(h>=l)
        {
            b=(h+l)/2;
            a=x*b/y;
            //cout << "a : " << a << "  b : " << b << endl;
//            a=117.1858168;
//            b=78.12387792;
            radius=sqrt(a*a+b*b)/2;
            angle=(radius*radius*2-b*b)/(2*radius*radius);
            angle=acos(angle)*(180/pi); ///acos yields in radian
            circle_slice=2*pi*radius*angle/360;
            perimeter=circle_slice+a;
            perimeter*=2;
           // cout << "per : " << perimeter << endl;
            if(abs(perimeter-400.0)<0.000001) break;
            else if(perimeter>400.0) h=b;
            else l=b;
        }
        caseno;
        cout << fixed << setprecision(9) <<a << ' ' << b << endl;
 
    }
}