#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
 
int main()
{
    int t,i;
    double ab,ac,bc,r,s,ae,de,ade,abc,bced,high,low,mid;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> ab >> ac >> bc >> r;
        high=ab,low=0;
        while(low<=high)
        {
            mid=(high+low)/2;
            ae=mid*(ac/ab);
            de=mid*(bc/ab);
            s=ab+bc+ac;
            abc=sqrt( s*(s-ab)*(s-bc)*(s-ac) );
            s=mid+ae+de;
            ade=sqrt( s*(s-mid)*(s-ae)*(s-de) );
            bced=abc-ade;
            if(ade/bced==r || abs((ade/bced)-r)<0.0000002 ) break;
            else if(ade/bced<r) low=mid;
            else high=mid;
        }
        cout << "Case " << fixed << setprecision(8) << i << ": " << mid << endl;
    }
}