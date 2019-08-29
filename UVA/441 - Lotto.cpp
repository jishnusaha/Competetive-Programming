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

    bool first=false;
    int n;
    il()
    {
        set<string> myset;
        set<string> :: iterator it;
        cin >> n;
        if(n==0) break;
        if(first) cout << endl;
        first=true;
        int s[n];
        loop(0,n-1) cin >> s[l];
        for(int i=0;i<(1<<n);i++)
        {
            int b[6],c=0;
            string p;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))!=0)
                {
                    if(c<6)
                    {
                        b[c]=s[j];
                        p=p+(char)('A'+j);
                    }
                    else
                    {
                        c++; break;
                    }
                    c++;
                }
            }
            if(c==6)
            {
                myset.insert(p);
                //cout << p << endl;;
                //loop(0,c-1)  cout << b[l] << ' ';  //printf("%d ",&b[l]);
                //cout << endl;
            }
        }
        for(it=myset.begin();it!=myset.end();it++)
        {
            string p=*it;
            cout << s[p[0]-'A'];
            loop(1,p.size()-1)
            {
                int v=s[p[l]-'A'];
                cout << ' ' << s[p[l]-'A'];
            }
            cout << endl;
        }

    }
}