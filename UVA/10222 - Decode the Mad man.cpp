#include <iostream>

using namespace std;

int main()
{
    char a[]={'\0','c','z','a','q','s','d','f','y','g','h','j','b','v','u','i','\0','w','\0','e','t','x','\0','\0','r','\0'};
    char num[]={'8','\0','`','1','2','3','4','5','6','7'};
    string s;
    while(getline(cin,s))
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]>='A' && s[i]<='Z') s[i]+=32;
            if(s[i]>='a' && s[i]<='z') s[i]=a[s[i]-97];
            else if(s[i]>='0' && s[i]<='9') s[i]=num[s[i]-48];
            else if(s[i]==']') s[i]='p';
            else if(s[i]=='[') s[i]='o';
            else if(s[i]=='=') s[i]='0';
            else if(s[i]=='-') s[i]='9';
            else if(s[i]==';') s[i]='k';
            else if(s[i]=='/') s[i]=',';
            else if(s[i]=='.') s[i]='m';
            else if(s[i]==',') s[i]='n';
            else if(s[i]=='\'') s[i]='l';
            else if(s[i]=='\\') s[i]=';';
        }
        cout << s << endl;
    }
}