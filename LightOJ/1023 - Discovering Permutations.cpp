#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(il,nl) for(int l=il;l<=nl;l++)
#define loop2(il2,nl2) for(int l2=il2;l2<=nl2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
#define tloop(tll,nt) for(int tl=tll;tl<=nt;tl++)
#define caseno printf("Case %d:",tl);
#define int_limit 2147483647
#define ll_limit 9223372036854775807
 
 
 
 
 
int n,k,c=1;
char permute_it[50],permutation_collection[50];;
bool taken[50];
void permutation_generator(int idx=0)
{
    if(c>k) return;
    if(idx==n)
    {
        for(int j=0;j<n;j++) cout << permutation_collection[j];
        cout << endl;
 
        c++;
        return;
 
    }
    for(int i=0;i<n;i++)
    {
        if(taken[i]==false)
        {
            taken[i]=true;
            permutation_collection[idx]=permute_it[i];
            permutation_generator(idx+1);
            taken[i]=false;
        }
    }
}
 
int main()
{
    int t;
    cin >> t;
    tloop(1,t)
    {
        cin >> n >> k;
        loop(0,n-1)
        {
            permute_it[l]=(char) 'A'+l;
            taken[l]=false;
        }
        caseno;
        cout << endl;
        c=1;
        permutation_generator();
 
    }
}
 