#include<bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    int a[26];
    int t;
    cin >> t;
    cin.ignore();
    for(int i=1;i<=t;i++)
    {
        getline(cin,line);
        memset(a,0,sizeof(a));
        int ans=0;
        for(int j=0;line[j]!='\0';j++)
        {
            if(line[j]>='a' && line[j]<='z')
            {
                a[line[j]-97]++;
                if(ans<a[line[j]-97]) ans=a[line[j]-97];
            }
            else if(line[j]>='A' && line[j]<='Z')
            {
                a[line[j]-65]++;
                if(ans<a[line[j]-65]) ans=a[line[j]-65];
            }
        }
        char c;
        for(int i=0;i<26;i++)
        {
            if(a[i]==ans)
            {
                c=i+97;
                cout << c;
            }
        }
        cout << endl;
    }
}