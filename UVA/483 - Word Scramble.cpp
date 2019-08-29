#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        int i,start,w=0;
        bool st=false;
        for(i=0;s[i]!='\0';i++)
        {
            if(!st && s[i]!=' ')
            {
                start=i;
                st=true;
            }
            else if(st && s[i]==' ')
            {
                if(w) cout << ' ';
                for(int j=i-1;j>=start;j--)
                {
                    cout << s[j];
                }
                st=false;
                w++;
            }

        }
        if(w) cout << ' ';
        for(int j=i-1;j>=start;j--)
        {
            cout << s[j];
        }
        cout << endl;

    }
}