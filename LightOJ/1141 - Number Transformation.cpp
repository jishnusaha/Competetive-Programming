#include<bits/stdc++.h>
using namespace std;
 
 
#define loop(i,n) for(int lc=i;lc<=n;lc++)
#define tloop(tn) for(int tlc=1;tlc<=tn;tlc++)
#define loop2(i2,n2) for(int lc2=i2;lc2<=n2;lc2++)
#define bloop(n,bn) for(int blc=n;blc>=bn;blc--)
#define il() while(true)
#define pi acos(-1)
#define rad_to_deg(angl) ((180*angl)/pi)
#define ll long long
#define pb push_back
#define casenos printf("Case %d: ",tlc);
#define casenonl printf("Case %d:\n",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfis(def_var) printf("%d ",def_var)
 
#define pfle(def_var) printf("%lld\n",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfls(def_var) printf("%lld ",def_var)
 
#define pfd(def_var) printf("%lf",def_var)
 
#define nl printf("\n");
 
const int p_limit=1010; ///say limit of prime you want to generate
bool status[p_limit+1];
int p=0;
int prime[200];
 
void sieve()
{
    prime[p]=2;
    p++;
    int i;
    int sqrtn=sqrt(p_limit);
    for(i=3;i<=sqrtn;i+=2)
    {
        if(status[i]==0)
        {
            prime[p]=i;
            p++;
            for(int j=i*i;j<=p_limit;j+=i*2)
            {
                status[j]=1;
            }
        }
    }
    status[1]=1;
    for(;i<=p_limit;i+=2)
    {
        if(status[i]==0)
        {
            prime[p]=i;
            p++;
        }
    }
}
vector<int> factors[1001];
void generate_factors(int n)
{
    int org=n;
 
    for(int i=0;i<p && prime[i]<org;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0) n/=prime[i];
            factors[org].pb(prime[i]);
        }
    }
    if(n>1 && org!=n) factors[org].pb(n);
}
 
int s,t;
 
int pushed[10001];
 
int bfs(int u,int trans=0)
{
    if(u==t) return 0;
 
    mem(pushed,false);
 
    queue< pair<int,int>  >q;
    q.push( make_pair(u,0) );
    pushed[u]=true;
    while(!q.empty())
    {
        u=q.front().first;
        trans=q.front().second;
        q.pop();
        for(int i=0;i<factors[u].size();i++)
        {
            int v=factors[u][i]+u;
            if(v==t) return trans+1;
            if(!pushed[v] && v<t)
            {
 
                pushed[v]=true;
                q.push( make_pair(v,trans+1)  );
            }
        }
    }
    return -1;
}
 
 
int main()
{
    sieve();
 
    for(int i=4;i<=1000;i++)
    {
        generate_factors(i);
    }
    int T;
    sfi(T);
    tloop(T)
    {
        sfii(s,t);
        casenos;pfie( bfs(s));
    }
}
 