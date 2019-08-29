#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define pi acos(-1)
#define ll long long

int main()
{
    int n,i=0,j=0;
    string s,w;
    char c[204];
    set<string>ss;
    while(getline(cin,s))
    {
        n=0;
        for(i=0;i<s.size();i++)
        {

            if(s[i]>='A' && s[i]<='Z') s[i]+=32;
            if(s[i]>='a' && s[i]<='z')
            {
                c[n]=s[i];
                n++;
            }
            else if(n)
            {
                c[n]='\0';
                n=0;
                w=c;
                ss.insert(w);
            }
        }
        if(n)
        {
            c[n]='\0';
            w=c;
            ss.insert(w);
        }
    }
    set<string> :: iterator p=ss.begin();
    for(;p!=ss.end();p++)
        cout << *p << endl;

}