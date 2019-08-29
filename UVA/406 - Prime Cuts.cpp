#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long

int status[(1000/32)+10];

void setstatus(int &n,int pos)
{
    n|=(1<<pos);
}

int check(int n,int pos)
{
    return n=n&(1<<pos);
}

void sieve()
{
    int c,i;
    int n=1010;
    int sqrtn=sqrt(n);
    for(i=3;i<=sqrtn;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i;j<=n;j+=2*i)
            {
                setstatus(status[j>>5],j&31);
            }
        }
    }
    //setstatus(status[0],1);
}

int main()
{
    sieve();
    int n,c;
    while(cin >> n >> c)
    {
        int a[n];
        int ln=0;
        loop(1,n)
        {
            if(check(status[l>>5],l&31)==0 && (l==2 || l&1) )
            {
                a[ln]=l;
                ln++;
            }
        }
        if(ln&1)
        {
            cout << n << ' ' << c << ":";

            int s=ln/2+1-c+1;
            int f=ln/2+1+c-1;
            if(s<1) { s=1; f=ln; }
            loop(s-1,f-1) cout << ' ' << a[l];
        }
        else
        {
            cout << n << ' ' << c << ":";
            int s=ln/2-c+1;
            int f=ln/2+1+c-1;
            if(s<1) { s=1; f=ln; }
            loop(s-1,f-1) cout << ' ' << a[l];
        }
        cout <<"\n\n";
    }
}