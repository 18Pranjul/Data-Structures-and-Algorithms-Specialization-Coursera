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
bool dfs(vector <ll> v[],bool vis[],bool vis1[],ll k)
{
    vis[k]=vis1[k]=1;
    for(ll i=0;i<v[k].size();i++)
    {
        ll y=v[k][i];
        if((!vis[y] && dfs(v,vis,vis1,y)) || vis1[y]) return 1;
    }
    vis1[k]=0;
    return 0;
}
int main() 
{
	fast_io;
	ll n,m,i;
	cin>>n>>m;
	vector <ll> v[n+5];
	for(i=0;i<m;i++)
	{
	    ll a,b;
	    cin>>a>>b;
	    v[a].pb(b);
	}
	bool vis[n+5]={false},vis1[n+5]={false},f=0;
	for(i=1;i<=n;i++) if(!vis[i] && !f) f=dfs(v,vis,vis1,i);
	cout<<(f?"1":"0");
	return 0;
}
