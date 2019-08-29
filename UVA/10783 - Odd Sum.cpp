#include <iostream>

using namespace std;

int main()
{
    int i,t,a,b,s;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        s=0;
        cin >> a >> b;
        if(a&1) s=a;
        else { s=a+1; a++;}
        for(a+=2;a<=b;a+=2) s+=a;
        cout << "Case " << i << ": " << s << endl;
    }
}