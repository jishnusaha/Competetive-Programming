#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
const int p_limit=1000000;


int status[(p_limit/32)+1]; //replace n(n is range of prime number)
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
//    int a[14]={2,3,3,7,11,13,17,19,23,29,31,37,41,43};
    int t;
    cin >> t;
    while(t--)
    {
        int l,u;
        cin >> l >> u;
        int l_limit=lower_bound(prime,prime+p-1,l)-prime;
        int u_limit=upper_bound(prime,prime+p-1,u)-prime;
        //cout << prime[l_limit] << ' ' << prime[u_limit] << endl;
        int d[120],index=0,value=0;
        loop(0,119) d[l]=0;
        loop(l_limit,u_limit-1-1) ///-1 because, upper_bound returns immediate bigger leftmost value
        {
            d[prime[l+1]-prime[l]]++;
            //cout << prime[l+1]-prime[l] << endl;
            if(d[prime[l+1]-prime[l]]>value)
            {
                index=prime[l+1]-prime[l];
                value=d[prime[l+1]-prime[l]];
                //cout << "index : " << index << endl;
            }
        }
        //cout << endl;
        if(!value) cout << "No jumping champion\n";
        else
        {
            //sort(d,d+120);
            int c=0,f=d[index];
            loop(0,119)
            {
                if(d[l]==f) c++;
            }
            if(c==1) cout << "The jumping champion is " << index << endl;
            else cout << "No jumping champion\n";
        }
    }

}