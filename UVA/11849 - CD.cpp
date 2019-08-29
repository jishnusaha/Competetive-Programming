#include<bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int l=i;l<=n;l++)
#define pi acos(-1)
#define ll long long

int main()
{
    int a,n,m,c=0;
    while(1)
    {
        c=0;
        scanf("%d %d",&n,&m);
        //cout << "input\n";
        if(n==0 && m==0) break;
        set<int>nn;
        loop(1,n)
        {
            scanf("%d",&a);
            nn.insert(a);
        }
        loop(1,m)
        {
            scanf("%d",&a);
            if(nn.find(a)!=nn.end()) c++;
        }
        cout << c << endl;
    }
}