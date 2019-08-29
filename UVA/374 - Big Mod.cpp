#include <bits/stdc++.h>

using namespace std;
long long big_mod(long long b,long long p,long long m)
{
    if(b==0) return 0;
    if(p==1) return b%m;
    if(p==0) return 1;
    long long r=big_mod(b,p/2,m);
    r*=r;
    r%=m;
    if(p&1) r*=b;
    r%=m;
    return r;

}
int main()
{

    long long b,p,m;
    while(scanf("%lld",&b)!=EOF)
    {
        scanf("%lld %lld",&p,&m);
        printf("%lld\n",big_mod(b,p,m));
    }
}