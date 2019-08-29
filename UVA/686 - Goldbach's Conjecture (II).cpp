#include<bits/stdc++.h>
using namespace std;

#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long

int prime[664585],p=0;
int n;

int status[1030];//2^15
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
    n=32768;
    for(i=3;i<=181;i+=2)
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
int upper_b(int l,int h,int k)
{
    while(h>=l)
    {
        int mid=(h+l)/2;
        if(prime[mid]==k)l=mid+1;
        else if(prime[mid]<k) l=mid+1;
        else h=mid-1;
    }
    return l;
}


int main()
{
    sieve();
    int n;
    scanf("%d",&n);
    while(n)
    {
        int c=0;
        int limit=upper_b(0,p-1,n/2);
        for(int i=0;i<limit;i++)
        {
            int v=n-prime[i];
            if((v&1 && check(status[v>>5],v&31)==0) || v==2)
            {
                //cout << prime[i] << "+" << v << "=" << n << endl;
                c++;
            }
        }
        printf("%d\n",c);
        cin >> n;
    }


}