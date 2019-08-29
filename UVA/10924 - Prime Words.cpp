#include<bits/stdc++.h>
using namespace std;

#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
int prime[1045];
void sieve()
{
     prime[0]=1;
     for(int  i=3;i<=32;i+=2)
     {
         if(prime[i]==0)
         {
             for(int j=i*i;j<=1045;j+=2*i)
             {
                 prime[j]=1;
             }
         }
     }
 }
 int main()
 {
     sieve();
     char a[25];
     int p=1;
     while(cin>>a)
     {

         int s=strlen(a);
         int c=0;
         loop(0,s-1)
         {
             if(a[l]>='a' && a[l]<='z')
             {
                 c+=(a[l]-'a');
                 c++;
             }
             else if(a[l]>='A' && a[l]<='Z')
             {
                 c+=(a[l]-'A');
                 c+=27;
             }
         }
         //cout << p <<  ". c : " <<  c << ". "<< endl;
         if( (c&1 || c==2) && prime[c]==0) cout << "It is a prime word.\n";
         else cout << "It is not a prime word.\n";
         p++;

     }
 }