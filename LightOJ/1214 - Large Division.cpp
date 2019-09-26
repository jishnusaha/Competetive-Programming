#include<bits/stdc++.h>
using namespace std;
 
#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(ti,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
 
int main()
{
    ll n,i,j;
    int t;
    cin >> t;
    string v;
    cin.ignore();
    tloop(1,t)
    {
        cin >> v;
        cin >> n;
        if(n<0) n=-n;
        if(v[0]=='-') i=1;
        else i=0;
        ll p=0;
        while(i<v.size())
        {
            while(p<=n)
            {
                p*=10;
                ll k=(v[i]-'0');
                p+=k;
                i++;
                if(i==v.size()) break;
            }
            p=p%n;
        }
        if(p) printf("Case %d: not divisible\n",tl);
        else printf("Case %d: divisible\n",tl);
    }
}