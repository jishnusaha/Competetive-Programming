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

int status[312510];//10^7
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
    n=10000000;
    for(i=3;i<=3162;i+=2)
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
    while(cin>>n)
    {
        if(!n) break;
        int m=-1,a=0,b=0;
        int limit=upper_b(0,p-1,n/2);
        //cout << "limit : " << limit << ". prime : " << prime[limit] << endl;
        for(int i=0;i<limit;i++)
        {
            int v=n-prime[i];
            //cout << "v : " << v << endl;
            if((v&1 && check(status[v>>5],v&31)==0) || v==2)
            {

                if((v-prime[i])>m){a=prime[i]; b=v; m=v-prime[i];}
            }
        }
        if(a) printf("%d = %d + %d\n",n,a,b);
        else printf("Goldbach's conjecture is wrong.\n");
    }


}