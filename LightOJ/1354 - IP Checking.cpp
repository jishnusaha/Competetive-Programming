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
    cin.ignore();
 
    tloop(1,t)
    {
        string s1,s2;
        int a1=0,b1=0,c1=0,d1=0,a2=0,b2=0,c2=0,d2=0;
        getline(cin,s1);
        getline(cin,s2);
        int i,c=1;
        for(i=s2.size()-1;s2[i]!='.';i--)
        {
            if(s2[i]=='1')
            {
                d2+=c;
            }
            c*=2;
        }
        c=1;
        for(i--;s2[i]!='.';i--)
        {
            if(s2[i]=='1')
            {
                c2+=c;
            }
            c*=2;
        }
        c=1;
        for(i--;s2[i]!='.';i--)
        {
            if(s2[i]=='1')
            {
                b2+=c;
            }
            c*=2;
        }
        c=1;
        for(i--;i>=0;i--)
        {
            if(s2[i]=='1')
            {
                a2+=c;
            }
            c*=2;
        }
 
        //s1 manipulation
 
        for(i=0;s1[i]!='.';i++)
        {
            c=s1[i]-'0';
            a1=a1*10+c;
        }
        for(i++;s1[i]!='.';i++)
        {
            c=s1[i]-'0';
            b1=b1*10+c;
        }
        for(i++;s1[i]!='.';i++)
        {
            c=s1[i]-'0';
            c1=c1*10+c;
        }
        for(i++;i<s1.size();i++)
        {
            c=s1[i]-'0';
            d1=d1*10+c;
 
        } 
        if(a1==a2 && b1==b2 && c1==c2 && d1==d2) cout << "Case " << tl << ": Yes\n";
        else cout << "Case " << tl << ": No\n";
    }
}