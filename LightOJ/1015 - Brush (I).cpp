#include<iostream>
using namespace std;
int main()
{
    int T,N,d,du;
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cin >> N;
        du=0;
        for(int p=0;p<N;p++)
        {
            cin >> d;
            if(d<0) d=0;
            du = d+du;
        }
        cout << "Case " << i << ": " << du << endl;
    }
   
}