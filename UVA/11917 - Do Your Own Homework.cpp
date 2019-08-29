#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define pi acos(-1)
#define ll long long

int main()
{
    int n,i,j,t,d;
    cin >> t;
    string s;
    loop(1,t)
    {
        map<string,int>m;
        cin >> n;
        while(n--)
        {
            cin >> s;
            cin >> i;
            m.insert(make_pair(s,i));
        }
        cin >> d;
        cin >> s;
        if(m.find(s)!=m.end())
        {
            if(m[s]<=d) cout << "Case " << l << ": " <<"Yesss\n";
            else if(m[s]<=d+5) cout << "Case " << l << ": " << "Late\n";
            else cout << "Case " << l << ": " << "Do your own homework!\n";
        }
        else cout << "Case " << l << ": " << "Do your own homework!\n";


    }
}