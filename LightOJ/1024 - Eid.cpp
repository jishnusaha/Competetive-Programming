/*
    idea:
        lcm of the n numbers is the ans.
        ans may not fit to long long. use string for multiplication
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
#define pb push_back

#define pii pair< int,int >
#define pll pair< long long, long long >
#define pib pair< int,bool >

#define casenos printf("Case %d: ",tlc);
#define casenonl printf("Case %d:\n",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))


#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)

#define sfl(def_var) scanf("%lld",&def_var)
#define sfll(def_var,def_var2) scanf("%lld %lld",&def_var,&def_var2)
#define sflll(def_var,def_var2,def_var3) scanf("%lld %lld %lld",&def_var,&def_var2,&def_var3)

#define sfd(def_var) scanf("%lf",&def_var)


#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfis(def_var) printf("%d ",def_var)

#define pfle(def_var) printf("%lld\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfls(def_var) printf("%lld ",def_var)

#define pfd(def_var) printf("%lf",def_var)

#define nl printf("\n");

#define casenownl output << "Case " << tlc << ":\n";
#define casenows output << "Case " << tlc << ": ";

#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
#define BOOST		ios_base::sync_with_stdio(false);cin.tie(NULL)


const int p_limit=10100;

int status[p_limit];
int prime[10000],prime_size=0;

void factorization_sieve()
{

//    note:
//    this function  store in status array by the largest prime factor of a number
//    largest prime factor of 60 is 5 then, status[60] will contain 5
//    if a number is 2^n then largest prime factor of it is 2. but it is not stored.
//    so if you get a even number p and status[p]==0 then it's largest prime factor will be 2

    int i;
    for(i=3;i<p_limit/2;i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i;j<p_limit;j+=i) status[j]=i;
        }
    }
    while(i<p_limit)
    {
        if(status[i]==0) status[i]=i;
        i+=2;
    }

}
int lcm_factors[p_limit];

void prime_factorization(int n)
{
    if(n<=1) return;

    int largest_prime_divisor=status[n];
    if(largest_prime_divisor==0) largest_prime_divisor=2;
    int c=0;
    while(n%largest_prime_divisor==0)
    {
        c++;
        n/=largest_prime_divisor;
    }
    lcm_factors[largest_prime_divisor]=max(lcm_factors[largest_prime_divisor],c);
    prime_factorization(n);

}

ll get_power(int base,int power)
{
    if(base==0) return 0;
    if(base==1) return 1;
    if(power==0) return 1;
    if(power==1) return base;

    ll r=get_power(base,power/2);
    r*=r;
    if(power&1) r*=base;
    return r;
}


string string_summation(string s1,string s2)
{
    int i=s1.size()-1,j=s2.size()-1,p=0;
    string ans="";
    for(;j>=0&& i>=0;i--,j--)
    {
        int a=(int) (s1[i]-'0');
        int b=(int) (s2[j]-'0');
        p+=a+b;
        ans+=(char)( (p%10)+'0' );
        p/=10;

    }
    if(s1.size()>s2.size())
    {
        for(;i>=0;i--)
        {
            int a=(int) (s1[i]-'0');
            p+=a;
            ans+=(char)( (p%10)+'0' );
            p/=10;
        }
    }
    else
    {
        for(;j>=0;j--)
        {
            int b=(int) (s2[j]-'0');
            p+=b;
            ans+=(char)( (p%10)+'0' );
            p/=10;
        }
    }
    if(p!=0) ans+=(char)(p+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}

string int_to_string(long long value)
{
    if (value==0) return "0";

    string s="";
    while(value!=0)
    {
        s+=(char) ('0'+(value%10));
        value/=10;
    }
    reverse(s.begin(),s.end());///function of algorithm.h
    return s;
}
string string_multiplication(string s1,string s2)
{
    //string summation function is needed
    string ans[s2.size()],zero="";
    for(int i=s2.size()-1;i>=0;i--)
    {
        string temp=zero;
        int p=0,a=(int)(s2[i]-'0' );
        for(int j=s1.size()-1;j>=0;j--)
        {
            int b=(int)(s1[j]-'0' );
            p+=(a*b);
            temp+=(char) ( (p%10)+'0');
            p/=10;
        }
        while(p)
        {
            temp+=(char) ( (p%10)+'0');
            p/=10;
        }
        reverse(temp.begin(),temp.end());
        ans[i]=temp;
        zero+='0';
    }
    string result=ans[0];
    for(int i=1;i<s2.size();i++)
    {
        result=string_summation(result,ans[i]);
    }
    return result;
}
int main()
{
    factorization_sieve();
    int t;
    sfi(t);
    tloop(t)
    {
        int n;
        sfi(n);
        int a[n];
        int mx=-1;
        loop(0,n-1)
        {
            sfi(a[lc]);
            mx=max(mx,a[lc]);
        }
        loop(0,mx) lcm_factors[lc]=0;
        loop(0,n-1) prime_factorization(a[lc]);

        ll v;
        string ans="1";
        loop(1,mx)
        {
            if(lcm_factors[lc])
            {
                v=get_power(lc,lcm_factors[lc]);
                ans=string_multiplication( ans, int_to_string(v) );
            }
        }
        casenos;
        cout << ans << endl;
    }
}
