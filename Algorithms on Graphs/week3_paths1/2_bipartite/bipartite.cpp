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
	ll vis[n+5]={0},clr[n+5],c=1;
	for(i=0;i<m;i++)
	{
	    cin>>u>>v;
	    ad[u].pb(v);
	    ad[v].pb(u);
	}
	qll q;
	q.push(1);
	vis[1]=1;
	clr[1]=0;
	while(q.size())
	{      
	    ll z=q.front();
        q.pop();
        for(i=0;i<ad[z].size();i++)
        {
            ll y=ad[z][i];
            if(vis[y] && clr[y]==clr[z])
            {
                c=0;
                goto end;
            }
            if(!vis[y])
            {
                q.push(y);
                vis[y]=1;
                clr[y]=clr[z]^1;
            }
        }	
    }
	end:;
	cout<<c;
	return 0;
}
