#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll m[30][30],M[30][30];
ll eval(ll a,ll b,ll op)
{
    if(op=='*')
     return a*b;
    if(op=='-')
     return a-b;
    return a+b;
}
void update(ll i,ll j,ll n[],char op[])
{
    ll k,mn=INT_MAX,mx=INT_MIN,a,b,c,d;
    if(i==j)
    {
        m[i][j]=n[i];
        M[i][j]=n[i];
    }
    else
    {
        for(int k=i;k<j;k++)
        {
            a=eval(M[i][k],M[k+1][j],op[k]);
            b=eval(m[i][k],m[k+1][j],op[k]);
            c=eval(M[i][k],m[k+1][j],op[k]);
            d=eval(m[i][k],M[k+1][j],op[k]);
            mn=min(mn,min(a,min(b,min(c,d))));
            mx=max(mx,max(a,max(b,max(c,d))));
        }
        M[i][j]=mx;
        m[i][j]=mn;
    }
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	ll i,j,n[30],nl=0,opl=0;
	char op[30];
	cin>>s;
	for(i=0;i<s.length();i++)
	{
	    if(i%2==0)
	     n[nl++]=s[i]-48;
	    else
	     op[opl++]=s[i];
	}
	for(i=0;i<nl;i++)
	{
	    for(j=0;j<nl;j++)
	    {
	        update(j,j+i,n,op);
	    }
	}
	cout<<M[0][nl-1];
	return 0;
}
