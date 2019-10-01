#include <iostream>
 
using namespace std;
 
int main()
{
    int t,r1,c1,r2,c2,a,b,c,d,i,x,y;
    char p1,p2;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        if(r1&1) a=1;
        else a=2;
        if(c1&1) b=1;
        else b=2;
        if(r2&1) c=1;
        else c=2;
        if(c2&1) d=1;
        else d=2;
        if(a==1 && b==1 || a==2 && b==2) p1='w';
        else p1='b';
        if(c==1 && d==1 || c==2 && d==2) p2='w';
        else p2='b';
        if(p1!=p2) cout << "Case " << i << ": impossible\n";
        else
        {
            if(r1<r2)
            {
                x=r2-r1;
                if(c1<c2 && c1+x==c2) cout << "Case " << i << ": " << 1 << endl;
                else if(c2<c1 && c2+x==c1) cout << "Case " << i << ": " << 1 << endl;
                else cout << "Case " << i << ": " << 2 << endl;
            }
            else if(r1>r2)
            {
                x=r1-r2;
                if(c1<c2 && c1+x==c2) cout << "Case " << i << ": " << 1 << endl;
                else if(c2<c1 && c2+x==c1) cout << "Case " << i << ": " << 1 << endl;
                else cout << "Case " << i << ": " << 2 << endl;
            }
            else cout << "Case " << i << ": " << 2 << endl;
        }
    }
}
 