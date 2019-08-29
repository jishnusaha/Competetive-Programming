#include <iostream>

using namespace std;
int main()
{

    int a,b,t;
    cin >>t;
    while(t--)
    {
        cin >> a >> b;
        if(a<b) cout << "<\n";
        else if(a>b) cout << ">\n";
        else cout << "=\n";
    }
}