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
 
 
 
 
 
 
const int p_limit=1000100; 
int status[(p_limit/32)+1];
 
vector<int>prime;
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
 
long long get_power(long long base,int power)
{
    if(power==0) return 1;
    if(power&1)
    {
        return get_power(base,power-1)*base;
    }
    else
    {
        long long r=get_power(base,power/2);
        return r*r;
    }
 
}
int main()
{
    ///lcm( a,b,c )=L
    ///we know, lcm( a,b,c )=lcm( lcm(a,b),c )
    ///now,how lcm is calculated?
    /// calculate prime factors of a,b,c
    /// then we will take the factors from a,b,c following this condition
    /// if a,b,c all have the common prime factors we will take the factor which has biggest power
    /// and uncommon factors will be taken all
 
    bitwise_sieve();
    int t;
    sfi(t);
    tloop(t)
    {
        ll a,b,L;
        sfl(a);
        sfl(b);
        sfl(L);
        vector< pair<ll,int> > lcm_abc_factors,a_factors,b_factors;
 
        int sqrt_L=sqrt(L);
        int sqrt_b=sqrt(b);
        int sqrt_a=sqrt(a);
 
        ///computing factors of L,a,b
        ll temp_L=L,temp_a=a,temp_b=b;
        for(int i=0;(prime[i]<=sqrt_L || prime[i]<=sqrt_a || prime[i]<=sqrt_b ) && i<prime.size();i++)
        {
            if(temp_L==1 && temp_a==1 && temp_b==1) break;
 
            int c=0;
            while(temp_L%prime[i]==0)
            {
                c++;
                temp_L/=prime[i];
            }
            if(c) lcm_abc_factors.push_back( make_pair(prime[i],c) );
 
            c=0;
            while(temp_a%prime[i]==0)
            {
                c++;
                temp_a/=prime[i];
            }
            if(c) a_factors.push_back( make_pair(prime[i],c) );
 
            c=0;
            while(temp_b%prime[i]==0)
            {
                c++;
                temp_b/=prime[i];
            }
            if(c) b_factors.push_back( make_pair(prime[i],c) );
        }
 
        if(temp_L>1) lcm_abc_factors.push_back( make_pair(temp_L,1) );
        if(temp_a>1) a_factors.push_back( make_pair(temp_a,1) );
        if(temp_b>1) b_factors.push_back( make_pair(temp_b,1) );
 
        ///computing factors of lcm(a,b)
        vector< pair<ll,int> > lcm_ab_factors;
        for(int i=0;i<a_factors.size();i++)
        {
            bool found=false;
            ll p=a_factors[i].first;
            for(int j=0;j<b_factors.size();j++)
            {
                if(a_factors[i].first==b_factors[j].first)
                {
                    found=true;
                    lcm_ab_factors.push_back( make_pair(a_factors[i].first, max( a_factors[i].second,b_factors[j].second )  )  );
                    b_factors[j].second=0;
                    b_factors[j].first=0;
                    break;
                }
            }
            if(!found)
            {
                lcm_ab_factors.push_back(a_factors[i]);
                a_factors[i].second=0;
                a_factors[i].first=0;
            }
        }
        for(int i=0;i<b_factors.size();i++)
        {
            if(b_factors[i].first)
            {
                lcm_ab_factors.push_back(b_factors[i]);
            }
        }
 
        ///comparing lcm_abc_factors and lcm_ab_factors if lcm_abc possess  all factors of lcm_ab
        ///if not possess then solution is impossible
        ///because lcm(lcm(a,b),c )=lcm(a,b,c)
        ///so lcm_abc must have the all factors of lcm(a,b)
        /// and the power of factors must be bigger or equal in lcm_abc
 
        bool impossible=false;
        for(int i=0;i<lcm_ab_factors.size();i++)
        {
            bool found=false;
            for(int j=0;j<lcm_abc_factors.size();j++)
            {
                if(lcm_ab_factors[i].first==lcm_abc_factors[j].first)
                {
                    if(lcm_ab_factors[i].second<=lcm_abc_factors[j].second)
                    {
                        found=true;
                        break;
                    }
                }
            }
            if(!found)
            {
                impossible=true;
                break;
            }
        }
        if(impossible)
        {
            caseno;printf("impossible\n");
            continue;
        }
        ///now, solution exist
        ///computing c
        ///as lcm(lcm(a,b),c )=L and we have factors of lcm(a,b)
        ///we will compute c comparing the factors of lcm(a,b) and factors of L(lcm_abc_factors)
 
        ///here, if lcm_abc and lcm_ab has the same factors with the same power
        ///that means, that factor already exist in a or b so we will not take it
 
        ///but, if if lcm_abc and lcm_ab has the same factors but the power isn't same
        ///that means, c must have that factors with that bigger power
 
        ///as we are here, that means we already verified that lcm_abc has the factors
        ///greater or equal then lcm_ab
        ///so, now if we found any factor same and power is not equal it is obvious
        ///lcm_abc has that factor with bigger power so, we will simply take it
 
        ///if we found any factor that does not exist in lcm_ab that means that must exist in c
        ///so, we will take it without any condition
        ll c=1;
        for(int i=0;i<lcm_abc_factors.size();i++)
        {
            int j; bool found=false;
            for(j=0;j<lcm_ab_factors.size();j++)
            {
                if(lcm_abc_factors[i].first==lcm_ab_factors[j].first)
                {
                    found=true;
                    break;
                }
            }
            if(found )
            {
                if(lcm_abc_factors[i].second!=lcm_ab_factors[j].second)
                {
                    c*=get_power(lcm_abc_factors[i].first,lcm_abc_factors[i].second );
                }
            }
            else
            {
                c*=get_power(lcm_abc_factors[i].first,lcm_abc_factors[i].second);
            }
        }
        caseno; printf("%lld\n",c);
    }
}
 