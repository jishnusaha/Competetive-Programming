#include<bits/stdc++.h>
using namespace std;

#define tloop(ti,tn) for(int tl=ti;tl<=tn;tl++)
#define loop(i,n) for(int l=i;l<=n;l++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define ll long long
#define caseno printf("Case %d: ",tl);


int main()
{
    int n,i,j;
    while(cin >> n)
    {
        int a[n];
        loop(0,n-1)
        {
            scanf("%d",&a[l]);
        }
        int m;
        cin >> m;
        sort(a,a+n);
        int p=0,q=0;
        //loop(0,n-1) cout << a[l] << ' ';

        for(int i=0;i<n;i++)
        {
            if(m-a[i]<0) break;
            bool found=false;
            int k=m-a[i];
            int h=n-1,l=i+1;
            int mid=(h+l)/2;
//            cout << "\nsearching " << k << endl;

            while(h>=l)
            {
            //    cout << h << " " << l<< endl;
                if(a[mid]==k) {found=true;break;}
                else if(a[mid]<k) l=mid+1;
                else h=mid-1;
                mid=(h+l)/2;


            }
            if(found)
            {
  //              cout << "found : " << a[i] << " and " << m-a[i] << endl;
                if(p==0 && q==0)
                {
                    p=a[i];
                    q=m-a[i];
                }
                else if(q-p>m-a[i]-a[i])
                {
                    p=a[i];
                    q=m-a[i];
                }
            }

        }
        cout << "Peter should buy books whose prices are " << p << " and " << q << ".\n\n";
    }
}