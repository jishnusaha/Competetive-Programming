#include <bits/stdc++.h>

using namespace std;
int n;
int used[17],circle[16];
bool isprime(int p)
{

    if(p<4) return true;
    else if(p%2==0) return false;
    for(int i=3;i<=p/2;i+=2)
    {
        if(p%i==0) return false;
    }
    return true;
}

int generator(int indx)
{
    if (indx == n)
    {
        cout << circle[0];
        for(int i=1;i<indx;i++)  cout << ' ' << circle[i];
        cout << endl;
        return 0;
    }
    for (int i=2;i<=n;i++)
    {
        if (used[i]==0 && isprime((i+circle[indx-1])))
        {
            if(indx<(n-1))
            {
                used[i]=1;
                circle[indx]=i;
                int l=generator(indx+1);
                used[i]=0;
            }
            else if( isprime(i+circle[0]) )
            {
                used[i]=1;
                circle[indx]=i;
                int l=generator(indx+1);
                used[i]=0;
            }
        }
    }
}
int main()
{
    int i=1;
    while(cin >>n)
    {
        memset(used,0,sizeof(used));
        used[0]=1;
        circle[0]=1;
        if(i>1) cout << endl;
        cout << "Case " << i << ":\n";
        int l=generator(1);
        i++;
        //cout << "done\n";
    }
}