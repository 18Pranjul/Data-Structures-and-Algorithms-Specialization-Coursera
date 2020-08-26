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
	string s,t;
	cin>>s;
	ll n = s.size() , i , j ,top , bottom , m , k;
	t=s;
	sort(all(t));
	vll a(100,0) , r(n,0);
	vvll l(100);
	for(i=0;i<n;i++) r[i] = a[(int)s[i]]++;
	for(i=0;i<n;i++) l[t[i]].pb(i);
	Test
	{
	    cin>>t;
	    reverse(all(t));
	    m=t.size();
	    i=1;
	    if(l[t[0]].size()) top=l[t[0]][0] , bottom=l[t[0]][l[t[0]].size()-1];
	    else top = bottom+1;
	    while(i<m && top<=bottom)
	    {
	        j=top;
	        while(j<=bottom && s[j]!=t[i]) j++;
	        k=bottom;
	        while(k>=top && s[k]!=t[i]) k--;
	        if(k<j) top = bottom+1;
	        else top = l[t[i]][r[j]] , bottom = l[t[i]][r[k]];
	        i++;
	    }
	    cout<<bottom-top+1<<" ";
	}
	return 0;
}
