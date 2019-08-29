#include <iostream>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        for(int i=0;s[i]!='\0';i++) s[i]-=7;
        cout << s << endl;
    }
}