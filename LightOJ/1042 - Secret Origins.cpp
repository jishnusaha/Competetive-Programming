/*
    idea:
    notice the output changes from the input.
 
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
#define caseno printf("Case %d: ",tlc);
#define mem(arr,val) memset(arr,val,sizeof(arr))
 
 
#define sfi(def_var) scanf("%d",&def_var)
#define sfii(def_var,def_var2) scanf("%d %d",&def_var,&def_var2)
#define sfiii(def_var,def_var2,def_var3) scanf("%d %d %d",&def_var,&def_var2,&def_var3)
#define sfl(def_var) scanf("%lld",&def_var)
#define sfd(def_var) scanf("%lf",&def_var)
#define sfs(def_var) scanf("%s",&def_var)
 
 
#define pfie(def_var) printf("%d\n",def_var)
#define pfi(def_var) printf("%d",def_var)
#define pfl(def_var) printf("%lld",def_var)
#define pfd(def_var) printf("%lf",def_var)
#define nl printf("\n");
 
string convert;
 
void decimal_to_any_base(long long n,int b)
{
    convert="";
    if(n<b)
    {
         if(n<=9)
         {
             convert+=(char)('0'+n);
         }
         else
         {
             char c='A'+(n-10);
             convert+=c;
         }
 
         return ;
    }
    else
    {
        decimal_to_any_base(n/b,b);
        long long mod= n%b;
        if(mod<=9)
        {
            convert+=(char)('0'+mod);
        }
        else
        {
            char c='A'+(mod-10);
            convert+=c;
        }
    }
}
 
long long get_power(int base,int power)
{
    if(power==0) return 1;
    if(power&1)
    {
        return get_power(base,power-1)*base;
    }
    else
    {
        long long r=get_power(base,power/2);
        return r*r;
    }
 
}
long long convert_to_decimal(string p,int original_base)
{
    long long value=0;
    int c=0;
    for(int i=p.size()-1;i>=0;i--)
    {
        long long k;
        if( p[i]<='9') k=(long long)(p[i]-'0');
        else
        {
            k =(int) (p[i]-'A') +1;
        }
        long long sub=get_power(original_base,c);
        value+=(k*sub );
        c++;
    }
    return value;
}
int main()
{
    int t;
    sfi(t);
    tloop(t)
    {
        ll n;
        cin >> n;
 
        decimal_to_any_base(n,2);
        convert='0'+convert;
 
        int one_pos;
        bool one_found=false;
        for(one_pos=convert.size()-1;one_pos>=0;one_pos--)
        {
            if(one_found && convert[one_pos]=='0')
            {
                one_pos++;
                break;
            }
            if(convert[one_pos]=='1') one_found=true;;
        }
 
        int zero_pos=one_pos-1;
        for(;zero_pos>=0;zero_pos--)
        {
            if(convert[zero_pos]=='0') break;
        }
 
        convert[zero_pos]='1';
        convert[one_pos]='0';
 
        sort(convert.begin()+one_pos,convert.end());
 
        caseno ; printf("%lld\n", convert_to_decimal(convert,2) );
    }
}
 
