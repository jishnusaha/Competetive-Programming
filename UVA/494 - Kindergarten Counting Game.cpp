#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int i,c,j;
    while(getline(cin,s))
    {
        bool r=false;
        c=1;
        for(i=1;s[i]!='\0';i++)
        {
            if(r && ((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)))
            {
                c++;
                r=false;
            }
            else if(!(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122))
            {
                r=true;
            }
        }
        cout << c << endl;
    }
}
