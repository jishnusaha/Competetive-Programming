#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int l=i;l<=n;l++)
#define tloop(tn) for(int tl=1;tl<=tn;tl++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
 
#define ll long long
#define caseno printf("Case %d: ",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
int max_traveled=0,max_traveled_firstday=0;
int getmax(int a[],int n)
{
    int m=-INT_MAX;
    loop(0,n) if(m<a[l]) m=a[l];
    return m;
}
 
bool check_it(int a[],int n,int k,int m)
{
    ///we will try to walk maximum m distance par day
    int c=0,i;
    int collect[k+1];//collect the walking distance in every day
    loop(0,k) collect[l]=0;
    for(i=0;i<=n;i++)
    {
        if(k-c<=n-i) ///when camp sites are more then required journey day..  we may to pass multiple day campsite in one walking day
        {
           if(a[i]+collect[c]<=m) ///walking up to m
            {
                collect[c]+=a[i];
 
            }
            else ///now if we walk a[i] that will be more than m
            {
                ///so, walking a[i] in next day.so increment c
                c++;
                if(c>k || collect[c-1]==0 || collect[c-1]>m)
                {
                    ///if c>k that means we need to more walking day, if we walk m distance par day
                    /// if collect[c-1]==0 that means we did not walk in c-1's day that cant't be
                    ///if collect[c-1]>m, we are walking more than m distance, that's also invalid
                    return false;
                }
                collect[c]=a[i];
 
            }
 
        }
        else //now we can take the  rest days one by one per day
        {
            c++;
            if(c>k || collect[c-1]==0 || collect[c-1]>m)
            {
                ///if c>k that means we need to more walking day, if we walk m distance par day
                /// if collect[c-1]==0 that means we did not walk in c-1's day that cant't be
                ///if collect[c-1]>m, we are walking more than m distance, that's also invalid
                return false;
            }
            collect[c]=a[i];
 
        }
    }
    i--; ///i balanced as it incremented in the last iteration in the above loop
 
 
    if(c==k && i==n)
    {
        ///we came to walk maximum m, but may be we walk less then m
        ///so, getting the max traveled
        m=getmax(collect,c);
        max_traveled=m;
        max_traveled_firstday=collect[0];
        return true;
    }
    else return false;
 
}
bool print(int a[],int n,int k,int m)
{
    int c=0,i;
    int collect[k+1];
    loop(0,k) collect[l]=0;
    for(i=0;i<=n;i++)
    {
        if(k-c<=n-i)
        {
            if(a[i]+collect[c]<=m)
            {
                collect[c]+=a[i];
            }
            else
            {
                c++;
                collect[c]=a[i];
            }
 
        }
        else
        {
            c++;
            collect[c]=a[i];
        }
    }
 
 
    printf("%d\n",getmax(collect,k));
    for(int i=0;i<=k;i++) printf("%d\n",collect[i]);
 
}
int main()
{
    int t;
    cin >> t;
    tloop(t)
    {
        int n,k;
        cin >> n>> k;
        int a[n+1];
        int low=INT_MAX,high=0;
        for(int l=0;l<=n;l++)
        {
            cin >> a[l];
            if(a[l]<low) low=a[l];
            high+=a[l];
        }
 
        while(low<high)
        {
            int mid=(high+low)/2;
            //cout << "l : " << low << " h : " << high << " mid : " << mid << endl;;
            if(check_it(a,n,k,mid))
            {
                //cout << "return true\n";
                high=mid;
            }
            else
            {
              // cout << "return false\n";
                low=mid+1;
            }
        }
        caseno;
        print(a,n,k,max_traveled);
 
 
    }
}