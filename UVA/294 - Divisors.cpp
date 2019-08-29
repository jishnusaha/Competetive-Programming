#include<bits/stdc++.h>
using namespace std;

#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long

int prime[3450],p=0;
int n;

int status[1005];
void setstatus(int &n,int pos)
{
    n=n|(1<<pos);
}
int check(int n,int pos)
{
    return n&(1<<pos);
}
void sieve()
{
    int c,i;
    prime[0]=2;
    p=1;
    n=31622;
    for(i=3;i<=177;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            prime[p]=i;
            p++;
            for(int j=i*i;j<=n;j+=2*i)
            {
                setstatus(status[j>>5],j&31);
            }
        }
    }
    for(;i<=n;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            prime[p]=i;
            p++;
        }
    }
    setstatus(status[0],1);

}
int get_divisor(int n)
{
    int m=1;
    for(int i=0;i<p;i++)
    {
        int t=n;
        int c=0;
        while(t%prime[i]==0)
        {
            c++;
            t/=prime[i];
        }
        m*=(c+1);
    }
    return m;
}

int main()
{
    sieve();
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int lo,hi;
        scanf("%d %d",&lo,&hi);
        int div=0,value=0;
        loop(lo,hi)
        {
            int d=get_divisor(l);
            if(d>div)
            {
                value=l;
                div=d;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",lo,hi,value,div);
    }



}