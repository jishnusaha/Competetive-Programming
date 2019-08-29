#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2A,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
const int p_limit=10000000;


int status[(p_limit/32)+1]; //replace n(n is range of prime number)
int p=1,prime[664580];

void setstatus(int &n,int pos)
{
    n|=(1<<pos);
}

int check_status(int n,int pos)
{
    return n=n&(1<<pos);
}

void sieve()
{
    prime[0]=2;
    int c,i;
    int sqrtn=sqrt(p_limit);
    for(i=3;i<=sqrtn;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            prime[p]=i;
            p++;
            for(int j=i*i;j<=p_limit;j+=2*i)
            {
                setstatus(status[j>>5],j&31);
            }
        }
    }
    setstatus(status[0],1);
    for(;i<=p_limit;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            prime[p]=i;
            p++;
        }
    }
}

int main()
{
    sieve();
    ll a;
    while(cin >> a)
    {
        if(!a) break;
        if(a<0) a=-a;
        ll max_div=-1;
        ll i;
        ll ap[30],m=0; //ap stores prime factor
        for( i=0;i<p;i++)
        {
            if(a==1)
            {
                break;
            }
            if(a<10000000)
            {
                int aa=a;
                if(check_status(status[aa>>5],aa&31)==0 && (aa&1 || aa==2))
                {
                    if(max_div==-1) break; // it is prime <10000000
                    ap[m]=aa;
                    m++;
                    break;
                }
            }
            bool div=false;
            ll pp=prime[i];
            while(a%pp==0)
            {
                div=true;
                a/=pp;
            }
            if(div)
            {
                ap[m]=pp;
                m++;
            }

        }
        if(a>1 && m) //if m>0 then we got at least 1 prime factor. now taking another
        {
            ap[m]=a; // taking prime factor >10^7 (if have)
            m++;
        }
        if(m>1)cout << ap[m-1] << endl;
        else cout << -1 << endl;

    }
}