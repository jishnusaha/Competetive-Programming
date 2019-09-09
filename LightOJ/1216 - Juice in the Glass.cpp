#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int l=i;l<=n;l++)
#define tloop(tn) for(int tl=1;tl<=tn;tl++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define cos_inverse_inDegree(arg) (180/pi)*acos(arg)
#define sin_inverse_inDegree(arg) (180/pi)*asin(arg)
#define sin_inDegree(arg) sin((arg*pi)/180)
#define cos_inDegree(arg) cos((arg*pi)/180)
#define ll long long
#define caseno printf("Case %d: ",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
 
 
int main()
{
 
 
    int t;
    cin >> t;
    tloop(t)
    {
        double r1,r2,h,p;
        cin >> r1 >> r2 >> h >> p;
        double ac=sqrt(h*h+(r1-r2)*(r1-r2));
        double angle_alfa=acos( (h*h+ac*ac-(r1-r2)*(r1-r2))/(2*h*ac) );
 
        double angle_bita=pi/2-angle_alfa;
 
        double oa=r2/sin(angle_alfa);
        double od=oa*sin(angle_bita);
 
        double fh=(od+p)*r2/od;
        double v1=pi*fh*fh*(od+p)/3;
        double v2=pi*r2*r2*od/3;
        caseno;
        cout << fixed << setprecision(9) << v1-v2 << endl;
    }
}
 