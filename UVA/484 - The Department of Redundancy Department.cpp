#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define pi acos(-1)
#define ll long long


int main()
{
    int n,i=0,j;
    map<int,int> m;
    vector<int> v;
    while(cin >>n)
    {
        if(m.find(n)!=m.end()) m[n]++;
        else
        {
            m[n]=1;
            v.push_back(n);
        }
    }
    for(i=0;i<v.size();i++)
    {
        cout << v[i] << ' ' << m[v[i]] << endl;
    }


}
