#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(il,nl) for(int l=il;l<=nl;l++)
#define loop2(il2,nl2) for(int l2=il2;l2<=nl2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
#define tloop(tll,nt) for(int tl=tll;tl<=nt;tl++)
#define caseno printf("Case %d: ",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
 
 
int main()
{
    int t;
    double r1,r2,r3,res;
    scanf("%d",&t);
    tloop(1,t)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
 
        double c_area_r1=pi*r1*r1,c_area_r2=pi*r2*r2,c_area_r3=pi*r3*r3; ///area of circles
        double l1=r1+r2,l2=r2+r3,l3=r3+r1; ///triangle length
        double t_area=(l1+l2+l3)/2;
        t_area=t_area*(t_area-l1)*(t_area-l2)*(t_area-l3);
        t_area=sqrt(t_area);
 
        double angle_l1,angle_l2,angle_l3;
        angle_l1=(l2*l2+l3*l3-l1*l1)/(2*l2*l3);
        angle_l1=acos(angle_l1)*180/pi;
        angle_l2=(l1*l1+l3*l3-l2*l2)/(2*l1*l3);
        angle_l2=acos(angle_l2)*180/pi;
        angle_l3=(l2*l2+l1*l1-l3*l3)/(2*l2*l1);
        angle_l3=acos(angle_l3)*180/pi;
 
        double arc_c_area_r1= (c_area_r1*angle_l2)/360;
        double arc_c_area_r2= (c_area_r2*angle_l3)/360;
        double arc_c_area_r3= (c_area_r3*angle_l1)/360;
 
        res= t_area-arc_c_area_r1-arc_c_area_r2-arc_c_area_r3;
        caseno; printf("%.10lf\n",res);
    }
}
 