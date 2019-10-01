/*
	here is a patters,
	2=2
	3=2 * 3
	4=2 * 3 * 2
	5=2 * 3 * 2 * 5
	6=2 * 3 * 2 * 5
	7=2 * 3 * 2 * 5 * 7
	if, n is only a multiple of prime then
		lcm(n)=lcm(n-1)* that prime
	else
		lcm(n)=lcm(n-1)

	then let's see,
		lcm(16)= 2 * 3 * 2 * 5 * 7 * 2 * 3 * 11 * 13 * 2
		reform = 2 * 2 * 2 * 3 *(2 * 3 * 5 *  7 * 11 * 13)
								here all the primes exist
								<=16 uniquely
								every lcm possess such factors
								why calculate these multiple times
								we can pre-calculate the product of
								primes  and store in an array

		rest 2*2*2*3.
			 2^3*3
		see here prime exist <=sqrt(16)
			and prime 2 can divide 16 4 times here exist 3 times
				prime 3 can divide 16 2 (16/3=5 then 5/3=1) times here exist 1 time
		so, we will check all primes <=sqrt(n) and take those primes 1 times less

		important note:
			n&(p-1) yield n%p if p is 2^n
*/



#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int lc=i;lc<=n;lc++)
#define tloop(tn) for(int tlc=1;tlc<=tn;tlc++)
#define loop2(i2,n2) for(int lc2=i2;lc2<=n2;lc2++)
#define bloop(n,bn) for(int blc=n;blc>=bn;blc--)
#define il() while(true)
#define pi acos(-1)
#define rad_to_deg(angl) ((180*angl)/pi)
#define ll long long
#define caseno printf("Case %d: ",tlc);
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
 
 
 
const int p_limit=100000100; 
int status[(p_limit/32)+1];
 
int prime[5761461],p=0;
unsigned int prime_product[5761461];
ll mod=(1LL<<32)-1;
 
void setstatus(int &n,int pos)
{
    n|=(1<<pos);
}
 
int check_status(int n,int pos)
{
    return n=n&(1<<pos);
}
 
void bitwise_sieve()
{
    prime_product[p]=2;
    prime[p++]=2;
 
    int i;
    int sqrtn=sqrt(p_limit);
    for(i=3;i<=sqrtn;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            prime_product[p]=prime_product[p-1]*i;
            prime[p++]=i;
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
            prime_product[p]=prime_product[p-1]*i;
            prime[p++]=i;
        }
    }
}
int main()
{
    bitwise_sieve();
    int t;
    sfi(t);
    tloop(t)
    {
        int n;
        sfi(n);
        if(n==1)
        {
            caseno; pfie(1); continue;
        }
        ll ans=1;
        int sqrt_n=sqrt(n);
        for(int i=0;prime[i]<=sqrt_n;i++ )
        {
            int temp=n;
            temp/=prime[i];
            while(temp>=prime[i])
            {
                temp/=prime[i];
                ans*=prime[i];
                ans=ans&mod;
            }
        }
        int pos=upper_bound(prime,prime+p,n)-prime-1;
        ans*=prime_product[pos];
        ans=ans&mod;
        caseno; printf("%lld\n",ans);
    }
}
 