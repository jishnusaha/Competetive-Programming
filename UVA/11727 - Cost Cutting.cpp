#include <iostream>

using namespace std;
int main()
{

    int t,a,b,c,i;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> a >> b >> c;
        if(a>b && a>c)
        {
            if(b>c) cout << "Case " << i << ": "<< b << endl;
            else cout << "Case " << i << ": " << c << endl;
        }
        else if(b>a && b>c)
        {
            if(a>c) cout << "Case " << i << ": " << a << endl;
            else cout << "Case " << i << ": " << c << endl;
        }
        else
        {
            if(a>b) cout << "Case " << i << ": " << a << endl;
            else cout << "Case " << i << ": " << b << endl;
        }
    }
}