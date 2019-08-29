#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,sum,j;
    int a[]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    cin >> t;
    for( i=0;i<=t;i++)
    {
        string s;
        sum=0;
        getline(cin,s);
        for(j=0;s[j]!='\0';j++)
        {
            if(s[j]==' ') sum+=1;
            else sum+=a[s[j]-97];
        }
        if(i>0) cout << "Case #" << i << ": " << sum << endl;
    }

}