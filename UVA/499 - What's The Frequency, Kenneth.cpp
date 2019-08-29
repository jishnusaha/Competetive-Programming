#include<bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    int cap[26],sml[26];
    while(getline(cin,line))
    {
        memset(cap,0,sizeof(cap));
        memset(sml,0,sizeof(sml));
        int ans=0;
        for(int i=0;line[i]!='\0';i++)
        {
            if(line[i]>='a' && line[i]<='z')
            {
                sml[line[i]-97]++;
                if(ans<sml[line[i]-97]) ans=sml[line[i]-97];
            }
            else if(line[i]>='A' && line[i]<='Z')
            {
                cap[line[i]-65]++;
                if(ans<cap[line[i]-65]) ans=cap[line[i]-65];
            }
        }
        char c;
        for(int i=0;i<26;i++)
        {
            if(cap[i]==ans)
            {
                c=i+65;
                cout << c;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(sml[i]==ans)
            {
                c=i+97;
                cout << c;
            }
        }
        cout << ' ' << ans << endl;

    }
}
