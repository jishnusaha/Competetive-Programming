#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i=1;
    string s;
    while(1)
    {
        cin >> s;
        if(s=="*") break;
        if(s=="Hajj") cout << "Case " << i << ": Hajj-e-Akbar\n";
        else cout << "Case " << i << ": Hajj-e-Asghar\n";
        i++;
    }
}