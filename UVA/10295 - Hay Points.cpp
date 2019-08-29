#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define il() while(1)
#define pi acos(-1)
#define ll long long


int main()
{
    int n,m,v;
    cin >> m >>n;
    map<string,int> w;
    string s;
    cin.ignore();
    loop(1,m)
    {
        cin >> s;
        cin >> v;
        w[s]=v;
    }
    loop(1,n)
    {
        int sum=0;
        il()
        {
            cin >> s;
            if(s==".") break;
            if(w.find(s)!=w.end()) sum+=w[s];
        }
        cout << sum << endl;
    }
}