#include <iostream>
 
using namespace std;
 
int r,l,n;
void pushright(string s1,int q1[])
{
    if(r==n-1 && l==0 || l==r+1 ) cout << "The queue is full\n";
    else
    {
        int v=0,d=1;
        int length=s1.length()-1; //now length mean last index
        int p=s1[length--]-'0';
        for(; p>=0 && p<=9; )
        {
            v+=p*d;
            d*=10;
            p=s1[length--]-'0';
        }
        if(s1[++length]=='-') v=0-v;
        if(l==-1 && r==-1) {r++; l++; }
        else if(r==n-1 && l>0) r=0;
        else r++;
        q1[r]=v;
        cout << "Pushed in right: " << v << endl;;
    }
}
void pushleft(string s1,int q1[])
{
    if(r==n-1 && l==0 || l==r+1 ) cout << "The queue is full\n";
    else
    {
        int v=0,d=1;
        int length=s1.length()-1; //now length mean last index
        int p=s1[length--]-'0';
        for(; p>=0 && p<=9; )
        {
            v+=p*d;
            d*=10;
            p=s1[length--]-'0';
        }
        if(s1[++length]=='-') v=0-v;
        if(l==-1 && r==-1) {l++; r++;}
        else if(l<=0) l=n-1;
        else l--;
        q1[l]=v;
        cout << "Pushed in left: " << v << endl;
    }
}
void popleft(int q1[])
{
    if(r==-1 && l==-1) cout << "The queue is empty\n";
    else
    {
        int v=q1[l];
        if(l==r) {l=-1;r=-1;}
        else if(l==n-1) l=0;
        else l++;
        cout << "Popped from left: " << v << endl;
    }
}
 
void popright(int q1[])
{
    if(r==-1 && l==-1) cout << "The queue is empty\n";
    else
    {
        int v=q1[r];
        if(l==r) {l=-1; r=-1;}
        else if(r==0) r=n-1;
        else r--;
        cout << "Popped from right: " << v << endl;
    }
 
}
int main()
{
    int t,m,i;
    cin >>t;
    for(i=1;i<=t;i++)
    {
        cin >> n >> m;
        int q[n];
        r=-1,l=-1;
        cout << "Case " << i << ":\n";
        cin.ignore();
        for(int b=1;b<=m;b++)
        {
            string s;
            getline(cin,s);
            if(s[4]=='R')
            {
                pushright(s,q);
            }
            else if(s[4]=='L')
            {
                pushleft(s,q);
            }
            else if(s[3]=='L')
            {
                popleft(q);
            }
            else if(s[3]=='R')
            {
                popright(q);
 
            }
 
        }
    }
}