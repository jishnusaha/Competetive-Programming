/*
idea:
    all the knight will move to any one position where jump cost will be minimum.
    this position may be any position in the graph
   
    first, calculate for every position, how much 1-jump needed to move the rest position.
    for this we can use 4 dimensional array, where first 2 [][] will denote the source position  
                                               and last 2 [][] will denote the target position
                                               
    then, for every position, count the cost for the knights to be gathered on that place.
    minimum count will be ans.
                                               
*/
 
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
 
int n,m;
int mp[12][12][12][12];
 
int visit[12][12];
 
 
void make_map(int source_i,int source_j)
{
    mp[source_i][source_j][source_i][source_j]=0;
    queue< pair<int,int> >que;
    que.push( make_pair(source_i,source_j) );
    visit[source_i][source_j]=true;
    while(!que.empty())
    {
        int p=que.front().first;
        int q=que.front().second;
        int jump=mp[source_i][source_j][p][q];
        que.pop();
        if(p-2>0)
        {
            if(q-1>=1)
            {
                if(!visit[p-2][q-1])
                {
                    visit[p-2][q-1]=true;
                    que.push(make_pair(p-2,q-1));
                    mp[source_i][source_j][p-2][q-1]=jump+1;
                }
            }
            if(q+1<=m)
            {
                if(!visit[p-2][q+1])
                {
                    visit[p-2][q+1]=true;
                    que.push(make_pair(p-2,q+1));
                    mp[source_i][source_j][p-2][q+1]=jump+1;
                }
            }
        }
        if(p+2<=n)
        {
            if(q+1<=m)
            {
                if(!visit[p+2][q+1])
                {
                    visit[p+2][q+1]=true;
                    que.push(make_pair(p+2,q+1));
                    mp[source_i][source_j][p+2][q+1]=jump+1;
                }
            }
            if(q-1>=1)
            {
                if(!visit[p+2][q-1])
                {
                    visit[p+2][q-1]=true;
                    que.push(make_pair(p+2,q-1));
                    mp[source_i][source_j][p+2][q-1]=jump+1;
                }
            }
        }
        if(q-2>=1)
        {
            if(p+1<=n)
            {
                if(!visit[p+1][q-2])
                {
                    visit[p+1][q-2]=true;
                    que.push(make_pair(p+1,q-2));
                    mp[source_i][source_j][p+1][q-2]=jump+1;
                }
            }
            if(p-1>=1)
            {
                if(!visit[p-1][q-2])
                {
                    visit[p-1][q-2]=true;
                    que.push(make_pair(p-1,q-2));
                    mp[source_i][source_j][p-1][q-2]=jump+1;
                }
            }
 
        }
        if(q+2<=m)
        {
            if(p+1<=n)
            {
                if(!visit[p+1][q+2])
                {
                    visit[p+1][q+2]=true;
                    que.push(make_pair(p+1,q+2));
                    mp[source_i][source_j][p+1][q+2]=jump+1;
                }
            }
            if(p-1>=1)
            {
                if(!visit[p-1][q+2])
                {
                    visit[p-1][q+2]=true;
                    que.push(make_pair(p-1,q+2));
                    mp[source_i][source_j][p-1][q+2]=jump+1;
                }
            }
        }
    }
}
 
int main()
{
    int t=100;
    sfi(t);
    tloop(t)
    {
        sfii(n,m);
 
        string s;
        vector< pair< pair<int,int>, int > >pos;
        ///taking input string
        loop(1,n)
        {
            cin >> s;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!='.')
                {
                    int p=(int)(s[i]-'0');
                    pos.pb( make_pair( make_pair(lc,i+1),p  )  );
                }
            }
        }
       
        ///pre calculating the map. how 1-jump need to move one place to another places
        mem(mp,-1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                mem(visit,false);
                make_map(i,j);
            }
        }
        casenos;
        if(pos.size()<=1)
        {
            pfie(0); continue;
        }
 
        int ans=INT_MAX;
        for(int target_i=1;target_i<=n;target_i++)
        {
            for(int target_j=1;target_j<=m;target_j++)
            {
                bool possible=true;
                int temp=0;
                for(int j=0;j<pos.size();j++)
                {
                    int source_i=pos[j].first.first;
                    int source_j=pos[j].first.second;
                    int jump=pos[j].second;
                    int require_jump=mp[source_i][source_j][target_i][target_j];
 
                    if(require_jump==-1)
                    {
                        possible=false;
                        break;
                    }
                    temp+=require_jump/jump;
                    if(require_jump%jump>0) temp++;
                }
                if(possible)
                {
                    ans=min(ans,temp);
                }
            }
        }
        if(ans==INT_MAX) pfie(-1);
        else pfie(ans);
    }
}