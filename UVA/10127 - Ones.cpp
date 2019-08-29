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
    int n;
    while(cin >> n)
    {
        int c=0;;
        string s;
        ll p;
        do
        {
            s+="1";
            c++;
            p=0;
            int i=0;
            while(i<s.size())
            {
                while(p<=n)
                {
                    p*=10;
                    ll k=(s[i]-'0');
                    p+=k;
                    i++;
                    if(i==s.size()) break;
                }
                p=p%n;
            }
            //if(!p) break;
        }while(p);
        cout << c << endl;
    }
}