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
#define caseno printf("Case %d: ",tlc);
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
#define pb(def_var) push_back(def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define pfs(def_var) printf("%s",def_var)
#define pfsn(def_var) printf("%s\n",def_var)
 
int vampires[20001], lykans[20001];
bool rival[20001];
int vampire_count=0,lykan_count=0;
int seg_best_sum=0;

void dfs_visit(bool vamp,vector<int> matrix[],int pos)
{
    rival[pos]=0;
    if(vamp) vampire_count++;
    else lykan_count++;
 
    for(int i=0;i<matrix[pos].size();i++)
    {
        if(rival[ matrix[pos][i] ]!=0)
        {
            dfs_visit(!vamp,matrix,matrix[pos][i]);
        }
    }
}
void DFS(vector<int> matrix[])
{
    seg_best_sum=0;
    loop(0,20000)
    {
        vampires[lc]=0;
        lykans[lc]=0;
 
 
    }
    bool vamp=true;
 
    for(int i=1;i<20001;i++)
    {
        if(rival[i]!=0)
        {
            vampire_count=0,lykan_count=0;
            dfs_visit(true,matrix,i);
            seg_best_sum+=max(vampire_count,lykan_count);
        }
    }
}
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        vector<int> matrix[20001];
        int n,u,v;
        sfi(n);
        loop(0,n-1)
        {
            sfii(u,v);
            matrix[u].pb(v);
            matrix[v].pb(u);
            rival[u]=1;
            rival[v]=1;
 
        }
        DFS(matrix);
        caseno;
 
        cout << seg_best_sum << endl;
 
    }
 
}