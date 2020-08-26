#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define vll vector<ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define sll stack<ll>
#define qll queue<ll>
#define mp make_pair
#define f first
#define s second
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define Test ll T;cin>>T; while(T--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define init(x,n,v) for(ll i=0;i<=n;i++) x[i]=v;
#define all(x) x.begin(),x.end()
#define pi 3.14159265358979323846
ll MOD = 1e9+7 , MAX = 1e18;
int main() 
{
	fast_io;
	string s;
	cin>>s;
	set <string> ss;
	ll n = s.size() , i=0;
	while(i<n)
	{
	    s.insert(s.begin(),s[n-1]);
	    s.erase(s.begin()+n);
	    ss.insert(s);
	    i++;
	}
	while(ss.size())
	{
	    string k = *ss.begin();
	    ss.erase(ss.begin());
	    cout<<k[n-1];
	}
	return 0;
}
