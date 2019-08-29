#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define pi acos(-1)
#define ll long long


int main()
{
    int l,n,k,v;
    char c;
    cin >> n;
    while(n--)
    {
        map<char,int> m;
        cin >> k;
        cin.ignore();
        while(k--)
        {
            //cout << "k : " << k<< endl;
            cin >> c;
            cin >> v;
            m.insert(make_pair(c,v));
            //cout << "inserted : " << m[c] << endl;
        }
        cin >> l;
        cin.ignore();
        string s;
        char s1;
        int d=0,cent=0;
        while(l--)
        {
            getline(cin,s);
            for(int i=0;i<s.size();i++)
            {
                s1=s[i];
                if(m.find(s1)!=m.end())
                {
                    cent+=m[s1];
                    if(cent>=100)
                    {
                        d+=cent/100;
                        cent=cent%100;
                    }
                    //cout << s1 << "-" << m[s1] << "   ";
                }
            }
        }
        int c1=cent/10,c2=cent%10;
        cout << d << '.' << c1 << c2 << '$'<< endl;
    }
}