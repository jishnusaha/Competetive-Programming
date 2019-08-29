#include<bits/stdc++.h>

#include<cstdio>
using namespace std;

int main()
{
    char s[102][103];
    int i=0;
    int big_length=0;
    while(gets(s[i]))
    {
        if(strlen(s[i])>big_length) big_length=strlen(s[i]);
        i++;
    }

    for(int j=0;j<i;j++)
    {
        int l=strlen(s[j]);
        if(l<big_length)
        {
            for(int k=l;k<big_length;k++)
            {
                s[j][k]=' ';
            }
            s[j][big_length]='\0';
        }
    }
    for(int l=0;l<big_length;l++)
    {
        for(int k=i-1;k>=0;k--)
        {
            cout << s[k][l];
        }
        cout << endl;
    }



}