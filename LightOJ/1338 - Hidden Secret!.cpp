#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(il,nl) for(int l=il;l<=nl;l++)
#define loop2(il2,nl2) for(int l2=il2;l2<=nl2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
#define tloop(tll,nt) for(int tl=tll;tl<=nt;tl++)
#define caseno printf("Case %d: ",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
 
 
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    tloop(1,t)
    {
        int a[26],b[26];
        loop(0,25) {a[l]=0; b[l]=0;}
        string s;
        getline(cin,s);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z') a[s[i]-97]++;
            else if(s[i]>='A' && s[i]<='Z') a[s[i]-65]++;
        }
        getline(cin,s);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z') b[s[i]-97]++;
            else if(s[i]>='A' && s[i]<='Z') b[s[i]-65]++;
        }
        bool yes=true;
        loop(0,25)
        {
            if(a[l]!=b[l]) {yes=false; break;}
        }
        caseno
        if(yes) cout << "Yes\n";
        else cout << "No\n";
 
 
    }
}
 