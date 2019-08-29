#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,bt,ft,c,d;
    char s[100],s1[100],s2[100];
    string b[103],f[103],current,command;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        bt=-1,ft=-1;
        cout << "Case " << i << ":"<< endl;
        current="http://www.lightoj.com/";
        for(;;)
        {
            gets(s);
 
            for(c=0;s[c]!='\0' && s[c]!=' ';c++)
                s1[c]=s[c];
            s1[c]='\0';
            command=s1;
            if(command=="VISIT")
            {
                bt++;
                b[bt]=current;
                for(d=0,c++;s[c]!='\0';c++,d++)
                    s2[d]=s[c];
                s2[d]='\0';
                current=s2;
                cout << current << endl;
                ft=-1;
            }
            else if(command=="FORWARD")
            {
                if(ft==-1) cout << "Ignored" << endl;
                else
                {
                    bt++;
                    b[bt]=current;
                    current=f[ft];
                    ft--;
                    cout << current << endl;
                }
            }
            else if(command=="BACK")
            {
                if(bt==-1) cout << "Ignored" << endl;
                else
                {
                    ft++;
                    f[ft]=current;
                    current=b[bt];
                    bt--;
                    cout << current << endl;
                }
            }
            else if(command=="QUIT") break;
        }
 
    }
}