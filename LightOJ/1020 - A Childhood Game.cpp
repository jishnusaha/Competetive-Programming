#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int l=i;l<=n;l++)
#define tloop(tn) for(int tl=1;tl<=tn;tl++)
#define loop2(i2,n2) for(int l2=i2;l2<=n2;l2++)
#define bloop(n,bn) for(int bl=n;bl>=bn;bl--)
#define il() while(1)
#define pi acos(-1)
#define rad_to_deg(angl) ((180*angl)/pi)
#define ll long long
#define caseno printf("Case %d: ",tl);
 
 
int main()
{
 
    ///if alice moves first, then (3*k+1) position is the loosing position
    ///if bob moves first then,(3*k+1) and (3*k+2) is the winning position
    ///where k is positive integer including 0
    int t;
    cin >> t;
    tloop(t)
    {
        cin.ignore();
        int n;
        char p[8];
        bool alice=false;
        scanf("%d",&n);
        scanf("%s",&p);
 
        if(p[0]=='A')
        {
            ///it is alice's winning condition
            if(n%3!=1) alice=true;
        }
        else
        {
            ///it is bob's loosing condition
            if(n%3==0) alice=true;
        }
        caseno;
        if(alice) printf("Alice\n");
        else printf("Bob\n");
 
 
 
    }
 
}
 