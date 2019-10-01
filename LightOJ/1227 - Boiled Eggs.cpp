#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n,p,q;
        cin >> n >> p >> q;
        int a[n];
        for(int j=0;j<n;j++) cin >> a[j];
        int w=0,j;
        for(j=0;j<n;j++)
        {
            if(w+a[j]<=q && j<=p-1)w+=a[j];
            else break;
        }
        cout << "Case " << i << ": " << j << endl;
    }
}
 
