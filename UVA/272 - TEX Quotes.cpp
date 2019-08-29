#include<bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    int e=1;
    while(getline(cin,line))
    {
        for(int i=0;line[i]!='\0';i++)
        {
            if(line[i]=='"'&& e&1){ cout << "``"; e=2; }
            else if(line[i]=='"' && !(e&1) ) {cout << "''"; e=1;}
            else cout << line[i];
        }
        cout << endl;
    }
}