#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,n,j,m,d,i,s,sw,e;
    char c;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> n >> m;
        int a[n];
        for(j=0;j<n;j++)
            cin >> a[j];
        for(;m--;)
        {
            cin >> c;
            switch(c)
            {
            case 'S' :
                cin >> d;
                for(j=0;j<n;j++) a[j]=a[j]+d;
                break;
            case 'M' :
                cin >> d;
                for(j=0;j<n;j++) a[j]=a[j]*d;
                break;
            case 'D' :
                cin >> d;
                for(j=0;j<n;j++) a[j]=a[j]/d;
                break;
            case 'R' :
                s=0;
                e=n-1;
                for(;s<e;)
                {
                    sw=a[s];
                    a[s]=a[e];
                    a[e]=sw;
                    s++;
                    e--;
                }
                break;
            case 'P':
                cin >> s >> e;
                sw=a[e];
                a[e]=a[s];
                a[s]=sw;
            }
 
        }
        cout << "Case " << i << ":\n";
        for(j=0;j<n-1;j++) cout << a[j] << ' ';
        cout << a[j] << endl;
    }
}
 
