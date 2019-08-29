#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int i,j,k,n,m,z,c,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int >a;
        for(i=0;i<n;i++)
        {
            cin>>m;
            a.push_back(m);
        }
        c=0;
        z=0;
        for(i=1;i<n;i++)
        {
            z = 0;
            for(j=0;j<(n-i);j++)
            {
                if( a[j]>a[j+1] )
                {
                    swap(a[j+1],a[j]);
                    z = 1;
                    c++;
                }
            }
            if (z==0) break;
        }
 
        cout<<"Optimal train swapping takes "<<c<<" swaps."<<endl;
    }
}