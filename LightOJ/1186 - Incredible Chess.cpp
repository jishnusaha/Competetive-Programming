#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int j=1;j<=t;j++)
    {
        int n;
        cin >> n;
        int w[n],b[n];
        for(int i=0;i<n;i++) cin >> w[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int win=b[0]-w[0]-1;
        for(int i=1;i<n;i++)
        {
            win^=(b[i]-w[i]-1);
        }
        cout << "Case " << j << ": ";
        if(!win)  cout << "black wins\n";
        else cout << "white wins\n";
    }
}
 