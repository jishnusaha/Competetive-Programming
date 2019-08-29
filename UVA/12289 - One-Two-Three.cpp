#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,l;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        l=s.length();
        if(l==5) cout << 3 << endl;
        else if( (s[0]=='t' && s[1]=='w' ) || (s[1]=='w' && s[2]=='o' ) || (s[0]=='t' && s[2]=='o' ) ) cout << 2 << endl;
        else cout << 1 << endl;
    }
}