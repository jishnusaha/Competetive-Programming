#include<bits/stdc++.h>
using namespace std;

#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long


int prime[1000005];
int value[1000005];
int main()
{
    prime[0]=1;prime[1]=1;
    for(int i=3;i<1000;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<1000000;j+=i)
                prime[j]=1;
        }
    }
    int s,c=1,t;
    value[2]=1;
    for(int l=3;l<=999999;l+=2)
    {
        if(prime[l]==0)
        {
            t=l;
            s=t%10;
            t/=10;
            while(t)
            {
                s+=t%10;
                t/=10;
            }
            if(prime[s]==0 && (s&1 || s==2) ) c++;
            value[l]=c;
            value[l+1]=c;
        }
        else { value[l]=c; value[l+1]=c; }
    }
    scanf("%d",&c);
    int t1,t2,ans;
    tloop(1,c)
    {
        scanf("%d %d",&t1,&t2);
        if(t1!=0)
        {
            //cout << value[t2] << " " << value[t1-1] << endl;
            ans=value[t2]-value[t1-1];
        }
        else ans=value[t2];

        printf("%d\n",ans);

    }
}