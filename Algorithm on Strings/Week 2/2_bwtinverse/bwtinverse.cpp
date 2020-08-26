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
	string s,ss;
	cin>>s;
	ll n = s.size() , i , cur;
	ss=s;
	sort(all(ss));
	vll a(100,0) , r(n,0);
	vvll l(100);
	for(i=0;i<n;i++) r[i] = a[(int)s[i]]++;
	for(i=0;i<n;i++) l[ss[i]].pb(i);
	ss="";
	cur=0;
	ss.pb('$');
	while(s[cur]!='$') ss.pb(s[cur]) , cur = l[s[cur]][r[cur]];
	reverse(all(ss));
	cout<<ss;
	return 0;
}
