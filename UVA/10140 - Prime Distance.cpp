#include<bits/stdc++.h>
using namespace std;


#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
#define caseno printf("Case %d: ",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
const int p_limit=46340; ///comment out constraint and assign sqrt of upper limit in constraint

int status[p_limit/32+1];
vector<int>prime;

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
    prime.push_back(2);
    int c,i;
    int sqrtn=sqrt(p_limit);
    for(i=3;i<=sqrtn;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            prime.push_back(i);

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
            prime.push_back(i);
        }
    }
}

void seg_sieve(long long l,long long h,vector<int>&seg_prime) ///here 2 will be manually added if it belongs to range
{
    if(h<2) return;
    if(l<3)
    {
        l=3;
        seg_prime.push_back(2);
    }
    else if(!(l&1)) l++;
//    cout << "taking range : [" << l << "," << h << "]\n";
    bool seg_status[h-l+1];
    for(long long i=0;i<=h-l;i++) seg_status[i]=true;

//    cout << "seg_prime array size : " << sizeof(seg_status)/sizeof(bool) << endl;

    for(long long i=1;prime[i]*prime[i]<=h && i<prime.size();i++)
    {
        long long j=(long long)(l/prime[i])*prime[i];
        if(j<l) j+=prime[i];
        if(!(j&1)) j+=prime[i];
        for(;j<=h;j+=prime[i]*2)
        {
            if(j!=prime[i]) seg_status[j-l]=false;

        }
    }
    for(long long i=l;i<=h;i++)
    {
        if(i&1 && seg_status[i-l]==true)
        {
            seg_prime.push_back(i);
        }

    }

}

int main()
{
    sieve();///taking prime
    int l,h;
    while(cin >> l)
    {
        cin >> h;
        int max_dif=0,min_dif=int_limit,c1,c2,d1,d2;
        vector<int>seg_prime;

        seg_sieve(l,h,seg_prime);
//        cout << "total prime : " << seg_prime.size() << endl;
        int sz=seg_prime.size();

//        printing all primes
//        for(int i=0;i<sz;i++)
//        {
//            cout << seg_prime[i] << ' ';
//        }
//        cout << endl;


        for(int i=1;i<sz;i++)
        {
            if(seg_prime[i]-seg_prime[i-1]<min_dif)
            {
                c1=seg_prime[i-1];
                c2=seg_prime[i];
                min_dif=c2-c1;
                //cout << "c1 assigned : " << c1 << ". c2 assigned : " << c2 << endl;
            }
            if(seg_prime[i]-seg_prime[i-1]>max_dif)
            {
                d1=seg_prime[i-1];
                d2=seg_prime[i];
                max_dif=d2-d1;
            }
        }
        if(max_dif)
        {
            printf("%d,%d are closest, %d,%d are most distant.\n",c1,c2,d1,d2);
        }
        else printf("There are no adjacent primes.\n");

    }
}