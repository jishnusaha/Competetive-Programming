#include<bits/stdc++.h>
using namespace std;

#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long

int prime[4800],p=0;
int n;
int status[1450];//2^15
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
    n=46345;
    for(i=3;i<=215;i+=2)
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
    //cout << p << endl;

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
        bool printx=false;
        bool pr=true;
        cout << n << " = ";
        if(n==1){ cout << 1; pr=false; }
        if(n<0)
        {
            cout << -1;
            n=-n;
            printx=true;
            if(n==1) pr=false;
        }
        bool print2=true;
        if(pr)
        {
            for(int l=0;prime[l]<=n && l<p;l++)
            {
                //cout << "\nnow d: " << prime[l] << endl;
                while(n%prime[l]==0 && n>1)
                {
                    if(printx) cout << " x ";
                    printf("%d",prime[l]);
                    n/=prime[l];
                    printx=true;
                    print2=false;
                    //cout << "\nin while n: " << n << endl;
                }
                if(n==1) { break; }
            }

        }
        if(print2)
        {
            if(printx) cout << " x ";
            cout << n ;
        }
        cout << endl;
        cin >> n;
    }


}