#include<iostream>
using namespace std;
int main()
{
    int T,i,j,N,c,K,s,r[101];
    char d[10];
    cin >> T;
    for(i=1;i<=T;i++)
    {
        s=0;
        cin >> N;  
        for(j=0;N!=0;N--)
        {
            cin >> d;
            switch(d[0])
            {
            case 'd' :
                cin >> K;
                s=s+K;
                break;
            case 'r' :
                j++;
                r[j]=s;
            }
        }
        cout << "Case " << i << ":\n";
        for(c=1;c<=j;c++) cout << r[c] << endl;
    }
}