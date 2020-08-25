#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll root(ll a[],ll x)
{
    while(a[x]!=x)
    {
        a[x]=a[a[x]];
        x=a[x];
    }
    return x;
}
void Union(ll a[],ll x,ll y)
{
    ll rx=root(a,x),ry=root(a,y);
    if(rx<ry) a[ry]=rx;
    else a[rx]=ry;
}
int main() 
{
	fast_io;
	ll n,m;
	cin>>n>>m;
	ll a[n+5],i;
	for(i=1;i<=n;i++) a[i]=i;
	for(i=0;i<m;i++)
	{
	    ll x,y;
	    cin>>x>>y;
	    Union(a,x,y);
	}
	ll x,y;
	cin>>x>>y;
	if(root(a,x)==root(a,y)) cout<<"1";
	else cout<<"0";
	return 0;
}
