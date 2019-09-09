#include<iostream>
using namespace std;
int main()
{
    int T,x1,y1,x2,y2,x,y,M,i;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cout << "Case " << i << ":" << endl;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> M;
        for(;M>0;M--)
        {
            cin >> x >> y;
            if(x>x1 && x<x2 && y>y1 && y<y2)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}