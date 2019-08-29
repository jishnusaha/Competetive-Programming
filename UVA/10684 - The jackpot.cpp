#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    while(n)
    {
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int max_sum=0,max_end=0;
        for(int i=0;i<n;i++)
        {
            max_end+=a[i];
            if(max_end<0) max_end=0;
            else if(max_sum<max_end) max_sum=max_end;
        }
        if(max_sum>0) cout << "The maximum winning streak is " << max_sum <<".\n";
        else cout << "Losing streak.\n";
        cin >> n;
    }
}
