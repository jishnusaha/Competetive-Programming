#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long

const int p_limit=20000000;

pair <int,int> v[100001];

int status[(p_limit/32)+10];
int p=1,prime[78498];

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
    int i,a,b,c=0;
    bool take_a=true,take_b=false;
    setstatus(status[0],1);
    int sqrtn=sqrt(p_limit);
    for(i=3;i<=sqrtn;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            if(take_a) {a=i; take_a=false;}
            else
            {
                if(a==i-2)
                {
                    v[c].first=a;
                    v[c].second=i;
                    a=i;
                    c++;
                }
                else
                {
                    a=i;
                }
            }
            for(int j=i*i;j<=p_limit;j+=2*i)
            {
                setstatus(status[j>>5],j&31);
            }
        }
    }
    for(;c<100001;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            if(a==i-2)
            {
                v[c].first=a;
                v[c].second=i;
                a=i;
                c++;
            }
            else
            {
                a=i;
            }
        }
    }


}

int main()
{
    sieve();
    int n;
    while(cin >> n)
    {
        printf("(%d, %d)\n",v[n-1].first,v[n-1].second);
    }



}