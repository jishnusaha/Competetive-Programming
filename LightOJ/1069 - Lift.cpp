#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int T,i,m,l,d,s=0;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> m >> l;
        d=m-l;
        d=abs(d);
        s=d*4+3+5+3+m*4+3+5;
        cout << "Case " << i << ": " << s << endl;
    }
}
 