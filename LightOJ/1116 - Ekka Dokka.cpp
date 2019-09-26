#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long T,i,j,W,N,M,c,l,n;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> W;
        if(W&1) cout << "Case " << i << ": Impossible\n";
        else
        {
            for(j=2;j<=(W>>1);j+=2)
            {
                if( !(j&(j-1)) && (W&(j-1)==0) )
                {
                    n=1;
                    for(l=2;pow(l,n)!=j;)
                    {
                        n++;
                    }
                    l=W>>n;
                    if(l&1)
                    {
                        N=W/j;
                        M=j;
                        c=1;
                        break;
                    }
                }
                else if(W%j==0 && ((W/j)&1))
                {
                    N=W/j;
                    M=j;
                    c=1;
                    break;
                }
            }
        if(c==0) cout << "Case " << i << ": Impossible\n";
        else cout << "Case " << i << ": " << N << " "<< M << endl;
        }
    }
 
}
 