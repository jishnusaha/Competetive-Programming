#include<iostream>
using namespace std;
int main()
{
    int t,i,j,n,m,r;
    int h,l,mid,cap_check,container_count;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        l=0;
        cin >> n >> m;
        int c[n];
        for(j=0;j<n;j++) { cin >> c[j]; if( l< c[j]) l=c[j]; }
        h=l*n;
        while(l<=h)
        {
            r=0;
            mid=(h+l)/2;
            cap_check=mid;
            container_count=1;
            for(j=0;j<n;j++)
            {
                if(c[j]<=cap_check) cap_check-=c[j];
                else
                {
                    if(++container_count >m){ r=1; break;  }
                    cap_check=mid;
                    j--;
                }
            }
            if(r==1) l=mid+1;
            else h=mid-1;
        }
        cout << "Case " << i << ": " << l << endl;
    }

}