#include<bits/stdc++.h>
using namespace std;

#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long

int status[312510];//10^7
void setstatus(int &n,int pos)
{
    n|=(1<<pos);
}

int check(int n,int pos)
{
    return n=n&(1<<pos);
}

void sieve()
{
    int c,i;

    int sieve_size=2010;
    int sqrt_size=sqrt(sieve_size);
    for(i=3;i<=sqrt_size;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i;j<=sieve_size;j+=2*i)
            {
                setstatus(status[j>>5],j&31);
            }
        }
    }
    setstatus(status[0],1);
}
int main()
{
    sieve();
    int t;
    cin >> t;
    string s;
    int A[27],a[27],n[10];
    cin.ignore();
    tloop(1,t)
    {
        cin >> s;
        loop(0,26)
        {
            A[l]=0;
            a[l]=0;
        }
        loop(0,9)
        {
            n[l]=0;
        }
        loop(0,s.size()-1)
        {
            if(s[l]>='A' && s[l]<='Z')
            {
                int p=s[l]-'A';
                A[p]++;
                //cout << "in A" << endl;
            }
            else if(s[l]>='a' && s[l]<='z')
            {
                int p=s[l]-'a';
                a[p]++;
                //cout << "in a" << endl;
            }
            else
            {
                int p=s[l]-'0';
                n[p]++;
                //cout << "in 0" << endl;
            }
        }
        bool e=true;
        cout << "Case " << tl << ": ";
        loop(0,9)
        {
            if(check(status[n[l]>>5],n[l]&31)==0 && (n[l]&1 || n[l]==2) )
            {
                char c=(char)( '0'+l);

                cout << c;
                e=false;
            }

        }
        loop(0,25)
        {
            if(check(status[A[l]>>5],A[l]&31)==0 && (A[l]&1 || A[l]==2) )
            {
                char c=(char)( 'A'+l);
                cout << c;
                e=false;
            }

        }
        loop(0,25)
        {
            if(check(status[a[l]>>5],a[l]&31)==0 && (a[l]&1 || a[l]==2) )
            {
                char c=(char)( 'a'+l);
                cout << c;
                e=false;
            }

        }

        if(e) cout << "empty";
        cout << endl;
    }
}