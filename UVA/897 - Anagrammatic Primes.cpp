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




int n;//permutation,taken array size
int permutation_collection[50],permutation[50],primes[5050],p,value;
bool taken[50],possible;
vector<int>anagrammatic_primes;


const int p_limit=10000000; ///limit of primes
int status[(p_limit/32)+1];
int took[p_limit/32+1];
void setstatus(int &n,int pos)
{
    n|=(1<<pos);
}

int check_status(int n,int pos)
{
    return n=n&(1<<pos);
}

void permutation_generator(int idx=0) ///must assign false to the array taken before calling this function
{
    if(idx==n)
    {
        //for(int j=0;j<n;j++) //cout << permutation_collection[j] << ' ';
        ////cout << endl;
        //cout << value << ' ';
        if(check_status(status[value>>5],value&31)==0 && (value&1 || value==2) )
        {
            primes[p]=value;
            p++;
        }
        else possible=false;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(taken[i]==false)
        {
            taken[i]=true;
            //permutation_collection[idx]=permutation[i];
            value=value*10+permutation[i];
            permutation_generator(idx+1);
            taken[i]=false;
            value/=10;
        }
    }
}
void check_anagrammatic_primes(int k)
{
    //cout << "checking " << k << endl;
    n=0;
    while(k)
    {
        taken[n]=false;
        permutation[n]=k%10;
        k/=10;
        n++;
    }
    p=0;
    possible=true;
    value=0;
    //cout << "combinations are : ";
    permutation_generator();
    //cout << endl;
//    if(possible) //cout << "adding all\n";
//    else //cout << "ignoring all\n";
    if(possible)
    {
        loop(0,p-1)
        {
            setstatus(status[primes[l]>>5],primes[l]&31);
            setstatus(took[primes[l]>>5],primes[l]&31);
        }
    }
    else
    {
        loop(0,p-1)
        {
            setstatus(status[primes[l]>>5],primes[l]&31);
        }
    }

}





void sieve()
{
    int c,i;
    int sqrtn=sqrt(p_limit);
    for(i=3;i<=sqrtn;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0)
        {
            for(int j=i*i;j<=p_limit;j+=2*i)
            {
                setstatus(status[j>>5],j&31);
            }
        }
    }
    ////cout << "done\n";
    setstatus(status[0],1);
    anagrammatic_primes.push_back(2);
    for(i=3;i<=p_limit;i+=2)
    {
        if(check_status(status[i>>5],i&31)==0 )
        {
            check_anagrammatic_primes(i);

        }
    }
    loop(3,p_limit-1)
    {
        if(check_status(took[l>>5],l&31))
        {
            anagrammatic_primes.push_back(l);
        }
    }


}


int main()
{
    sieve();
//    cout << anagrammatic_primes.size() << endl;
//
//    loop(0,anagrammatic_primes.size()-1) cout << anagrammatic_primes[l] << ' ';

    int n;
    while(cin >>n)
    {
        if(!n)break;
        if(n>=991 || (n>=97 && n<=99) || (n>=7 && n<=9) )
        {
            cout << 0 << endl;
        }
        else
        {
            int l=upper_bound(anagrammatic_primes.begin(),anagrammatic_primes.end(),n)-anagrammatic_primes.begin();
            cout << anagrammatic_primes[l] << endl;
        }
    }

}