#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)

int main()
{
    for(;;)
    {
        int a,b;
        cin >> a >>b;
        if(a==-1 && b==-1) break;
        if(a==b) cout << 0 << endl;
        else if(a<b)
        {
            if((b-a)>(a+1+99-b)) cout << a+1+99-b << endl;
            else cout << b-a << endl;
        }
        else
        {
            if((a-b)>(99-a+1+b)) cout << 99-a+1+b << endl;
            else cout << a-b << endl;
        }
    }

}