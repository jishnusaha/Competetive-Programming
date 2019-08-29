#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define pi acos(-1)
#define ll long long

int main()
{
    int n;
    cin >> n;
    string s1,s2;
    map<string,string>ss;
    cin.ignore();
    for(int i=1;i<=n;i++)
    {
        getline(cin,s1);
        getline(cin,s2);
        ss.insert(make_pair(s1,s2));
    }
    int q;
    cin >> q;
    cin.ignore();
    while(q--)
    {
        getline(cin,s1);
        cout << ss[s1] << endl;
    }
}