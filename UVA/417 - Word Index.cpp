#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define il() while(1)
#define pi acos(-1)
#define ll long long


int main()
{
    string create="a";
    char c='a';
    string s;
    map<int,string>list_s;
    map<string,int>m;
    loop(1,26)
    {
        //create=create+l;
        create=c;
        list_s[l]=create;
        m[create]=l;
        s=c;
        c++;
    }
    int first=1,last=26,counter=27;
    bool b=false;
    il()
    {
        bool fi=true;
        int f;
        loop(first,last-1)
        {
            int i_first=first;

            string s1=list_s[l];
            int sz=s1.size();
            char sc=s1[sz-1];
            sc++;
            for(c=sc;c<='z';c++)
            {
                s=list_s[l]+c;
                list_s[counter]=s;
                m[s]=counter;
                if(fi)
                {
                    fi=false;
                    f=counter;
                }
                counter++;
                if(counter>83683)
                {
                    b=true;
                    break;
                }
            }
            if(b) break;
        }
        if(b) break;
        first=f;
        last=counter-1;
    }
    while(cin >> s)
    {
        if(m.find(s)!=m.end()) cout << m[s] << endl;
        else cout << 0 << endl;

    }
}