#include <iostream>
using namespace std;
 
bool check_leap(int a)
{
    if(a%100==0)
    {
        if(a%400==0) return true;
        else return false;
    }
    else if(a%4==0) return true;
    else return false;
}
 
int leap_count(int a)
{
    int k;
    if(a>=1000000000)
    {
        int t=a;
        t/=1000000000;
        t=t*242500000+leap_count(a-t*1000000000);
        return t;
    }
    else if(a>=100000000)
    {
        int t=a;
        t/=100000000;
        t=t*24250000+leap_count(a-t*100000000);
        return t;
    }
    else if(a>=10000000)
    {
        int t=a;
        t/=10000000;
        t=t*2425000+leap_count(a-t*10000000);
        return t;
    }
    else if(a>=1000000)
    {
        int t=a;
        t/=1000000;
        t=t*242500+leap_count(a-t*1000000);
        return t;
    }
    else if(a>=100000)
    {
        int t=a;
        t/=100000;
        t=t*24250+leap_count(a-t*100000);
        return t;
    }
    else if(a>=10000)
    {
        int t=a;
        t/=10000;
        t=t*2425+leap_count(a-t*10000);
        return t;
    }
    else
    {
        int t=0;
        for(int l=4;l<=a;l+=4)
        {
            if(check_leap(l)) t++;
 
        }
        return t;
 
    }
 
}
 
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        string s1,s2;
        cin >> s1 >> s2 >> a;
        if(s1!="January" && s1!="February") a++;
        cin >> s1 >> s2 >> b;
        if(s1=="January") b--;
        else if(s1=="February")
        {
            int v=0;
            for(int i=0;s2[i]!=',';i++)
            {
                v=v*10+(s2[i]-'0');
 
            }
            if(v<29) b--;
        }
        a--;
        int result=leap_count(b)-leap_count(a);
        cout << "Case " << i << ": "<< result << endl;
 
    }
}
 
 
