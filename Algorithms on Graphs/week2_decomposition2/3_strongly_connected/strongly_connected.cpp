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
void fill(vector <ll> v[],ll vis[],stack <ll> &st,ll k)
{
    vis[k]=1;
    for(ll i=0;i<v[k].size();i++)
    {
        ll y=v[k][i];
        if(!vis[y]) fill(v,vis,st,y);
    }
    st.push(k);
}
void dfs(vector <ll> v[],ll vis[],ll k)
{
    vis[k]=1;
    for(ll i=0;i<v[k].size();i++)
    {
        ll y=v[k][i];
        if(!vis[y]) dfs(v,vis,y);
    }
}
int main() 
{
	fast_io;
	ll n,m,i;
	cin>>n>>m;
	vector <ll> v[n+5],vr[n+5];
	for(i=0;i<m;i++)
	{
	    ll a,b;
	    cin>>a>>b;
	    v[a].pb(b);
	    vr[b].pb(a);
	}
	ll vis[n+5]={0};
	stack <ll> st;
	for(i=1;i<=n;i++)
	 if(!vis[i]) fill(v,vis,st,i);
	ll visr[n+5]={0},c=0;
	while(st.size())
	{
	    ll k=st.top();
	    st.pop();
	    if(!visr[k]) dfs(vr,visr,k),c++;
	}
	cout<<c;
	return 0;
}
