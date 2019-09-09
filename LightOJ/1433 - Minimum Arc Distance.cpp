#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int T,i;
    double ox,oy,ax,ay,bx,by,oa,ob,ab,s,a;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> ox >> oy >> ax >> ay >> bx >> by;
        oa= (oy-ay)*(oy-ay)+(ox-ax)*(ox-ax);
        oa=sqrt(oa);
        ob= (oy-by)*(oy-by)+(ox-bx)*(ox-bx);
        ob=sqrt(ob);
        ab= (ay-by)*(ay-by)+(ax-bx)*(ax-bx);
        ab=sqrt(ab);
        a=acos((oa*oa+ob*ob-ab*ab)/(2*oa*ob));
        s=a*oa;
        cout << "Case " << i << ": ";
        cout << fixed << setprecision(9) << s << endl;
    }
}
 
