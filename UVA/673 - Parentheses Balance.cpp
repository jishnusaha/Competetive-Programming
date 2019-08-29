#include<bits/stdc++.h>
using namespace std;
int t;
char s[130];
void push(char x)
{
    t++;
    s[t]=x;
}
void pop()
{
    t--;
}
char top()
{
    if(t>=0) return s[t];
    else return '\0';
}
int main()
{
    int n,i,r;
    char p;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        t=-1;
        r=1;
        char e[130];
        gets(e);
        for(i=0;e[i]!='\0';i++)
        {
            if(e[i]=='(' || e[i]=='[') push(e[i]);
            else if(e[i]==')' || e[i]==']')
            {
                p=top();
                if(e[i]==')' && p=='(' || e[i]==']' && p=='[' ) pop();
                else {r=0; break;}
            }
        }
        if(r && t==-1) cout << "Yes\n";
        else cout << "No\n";
    }
}