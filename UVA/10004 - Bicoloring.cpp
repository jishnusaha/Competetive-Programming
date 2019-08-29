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

#define pii pair< int,int >
#define pll pair< long long, long long >
#define pib pair< int,bool >

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

int main()
{
    int n,edge,u,v;
    while(cin >> n)
    {
        if(!n) break;
        sfi(edge);
        vector<int>adj_list[n];
        loop(1,edge)
        {
            sfii(u,v);
            adj_list[u].pb(v);
            adj_list[v].pb(u);
        }
        bool pushed[n],color[n],possible=true;;
        loop(0,n-1)
        {
            pushed[lc]=false;
            color[lc]=false;
        }
        pushed[0]=true;
        color[0]=false;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            for(int i=0;i<adj_list[u].size();i++)
            {
                v=adj_list[u][i];
                if(!pushed[v])
                {
                    pushed[v]=true;
                    color[v]=!color[u];
                    q.push(v);
                }
                else if(color[v]==color[u])
                {
                    possible=false;
                    break;
                }
            }
            if(!possible) break;
        }
        if(possible) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");

    }
}