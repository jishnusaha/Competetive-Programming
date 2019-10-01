#include<bits/stdc++.h>
using namespace std;
 
#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define caseno(i) printf("Case %d:",i);
#define ll long long
 
 
int main()
{
    int t;
    cin >> t;
    tloop(1,t)
    {
        ll  p,l;
        cin >> p >> l;
        printf("Case %d:",tl);
        ll div[100000],d=0;
        p-=l; //now p is total piaju that had been eaten
        ll sqrtp=sqrt(p);
        if(1>l){div[0]=1;d++;}
        if(p>l && div[d-1]!=p){ div[d]=p; d++;}
        for(ll i=2;i<=sqrtp;i++)
        {
            if(p%i==0)
            {
                if(i>l&& div[d-1]!=i) {div[d]=i;d++;}
                ll k=p/i;
                if(k>l && div[d-1]!=k) {div[d]=k;d++;}
            }
        }
        if(d)
        {
            sort(div,div+d);
            loop(0,d-1) cout << ' ' << div[l];
        }
        else cout << " impossible";
        cout << endl;
    }
 
}
 
