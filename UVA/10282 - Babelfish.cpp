#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define il() while(1)
#define pi acos(-1)
#define ll long long


int main()
{
    map<string,string> w;
    string s1,s2;
    loop(1,100000)
    {
        cin >> s1;
        if(s1=="\n") break;
        cin >> s2;
        w[s2]=s1;
    }
    cin.ignore();
    loop(1,100000)
    {
        cin >> s1;
        if(w.find(s1)!=w.end())cout << w[s1] << endl;
        else cout << "eh\n";
    }

}