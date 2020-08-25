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
#define vll vector<ll>
#define sll stack<ll>
#define qll queue<ll>
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
int main() 
{
	fast_io;
	ll n,m,i,u,v;
	cin>>n>>m;
	vll ad[n+5];
	ll vis[n+5]={0},lvl[n+5];
	for(i=1;i<=n;i++) lvl[i]=-1;
	for(i=0;i<m;i++)
	{
	    cin>>u>>v;
	    ad[u].pb(v);
	    ad[v].pb(u);
	}
	cin>>u>>v;
	qll q;
	q.push(u);
	vis[u]=1;
	lvl[u]=0;
	while(q.size())
	{
	    ll z=q.front();
	    q.pop();
	    for(i=0;i<ad[z].size();i++)
	    {
	        ll y=ad[z][i];
	        if(!vis[y])
	        {
	            q.push(y);
	            vis[y]=1;
	            lvl[y]=lvl[z]+1;
	        }
	    }
	}
	cout<<lvl[v];
	return 0;
}
