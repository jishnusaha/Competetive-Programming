#include<bits/stdc++.h>
using namespace std;
 
#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
#define caseno printf("Case %d: ",tl);
 
 
int main()
{
    int t;
    cin >> t;
    tloop(1,t)
    {
        int n;
        cin >> n;
        pair<int,string> info[n];
        cin.ignore();
        loop(0,n-1)
        {
            string s;
            int a,b,c;
            cin >> s;
            cin >> a >> b >> c;
            info[l].second=s;
            info[l].first=a*b*c;
        }
        sort(info,info+n);
        if(info[n-1].first>info[0].first) //change1 is thief
        {
            cout << "Case " << tl << ": " << info[n-1].second << " took chocolate from " << info[0].second << endl;
        }
        else cout << "Case " << tl << ": no thief\n";
    }
}
 
