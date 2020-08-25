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
	ll n,m,i,a,b,w;
	cin>>n>>m;
	vector <pll> v[n+5];
	for(i=0;i<m;i++)
	{
	    cin>>a>>b>>w;
	    v[a].pb({b,w});
	}
	cin>>a>>b;
	priority_queue <pll,vector <pll>,greater<pll>> q;
	q.push({0,a});
	ll vis[n+5]={0};
	while(q.size() && q.top().s!=b)
	{
	    pll z=q.top();
	    q.pop();
	    vis[z.s]=1;
	    for(i=0;i<v[z.s].size();i++)
	    {
	        pll y=v[z.s][i];
	        if(!vis[y.f]) q.push({y.s+z.f,y.f});
	    }
	}
	if(q.size()) cout<<q.top().f;
	else cout<<"-1";
	return 0;
}
