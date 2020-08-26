#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define vll vector<ll>
#define vs vector<string>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define vvpll vector<vpll>
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
#define MOD 1000000007
#define MAX 2000000000000000000
#define MAXN 100005
void inout()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
}
set <ll> ans;
void SortCharacters(string &s , vll &order)
{
    ll n = s.size() , i;
    vll count(26);
    order[0] = n - 1;
    for(i = 0 ; i < n - 1 ; i++) count[s[i] - 'A']++;
    for(i = 1 ; i < 26 ; i++) count[i] += count[i - 1];
    for(i = n - 2 ; i >= 0 ; i--) order[count[s[i] - 'A']--] = i;
}
void ComputeCharClasses(string &s , vll &order , vll &Class)
{
	ll n = s.size() , i;
	Class[n - 1] = 0;
	for(i = 1 ; i < n ; i++)
	{
		Class[order[i]] = Class[order[i - 1]];
		if(s[order[i]] != s[order[i - 1]]) Class[order[i]]++;
	}
}
void SortDoubled(string &s , ll l , vll &order , vll &Class)
{
	ll n = s.size() , i;
	vll count(n) , newOrder(n);
	for(i = 0 ; i < n ; i++) count[Class[i]]++;
	for(i = 1 ; i < n ; i++) count[i] += count[i - 1];
	for(i = n - 1 ; i >= 0 ; i--)
	{
		ll st = (order[i] - l + n) % n;
		newOrder[--count[Class[st]]] = st;
	}
	swap(order , newOrder);
}
void UpdateClasses(vll &order , vll &Class , ll l)
{
	ll n = order.size() , i;
	vll newClass(n);
	newClass[order[0]] = 0;
	for(i = 1 ; i < n ; i++)
	{
		ll cur = order[i] , prev = order[i - 1] , mid = (cur + l) % n , midPrev = (prev + l) % n;
		newClass[cur] = newClass[prev];
		if(Class[cur] != Class[prev] || Class[mid] != Class[midPrev]) newClass[cur]++; 
	}
	swap(Class , newClass);
}
void PatternMatchingWithSuffixArray(string &s , string &t , vll &order)
{
	ll n = s.size() , m = t.size() , l , r , mid , st = n , en = -1;
	l = 0 , r = n - 1;
	while(l <= r) 
	{
		mid = (l + r) / 2;
		if(s.substr(order[mid] , m) >= t) r = mid - 1  , st = mid;
		else l = mid + 1;
	}
	l = 0 , r = n - 1;
	while(l <= r) 
	{
		mid = (l + r) / 2;
		if(s.substr(order[mid] , m) <= t) l = mid + 1 , en = mid;
		else r = mid - 1;
	}
	while(st <= en) ans.insert(order[st++]);
}
int main() 
{
    //inout();
    string s;
    cin>>s;
    s += "$";
    ll n = s.size() , l = 1 , q;
    vll order(n) , Class(n);
    SortCharacters(s , order);
    ComputeCharClasses(s , order , Class);
    while(l < n)
    {
    	SortDoubled(s , l , order , Class);
    	UpdateClasses(order , Class , l);
	    l *= 2;
    }
    cin>>q;
    while(q--)
    {
    	string t;
    	cin>>t;
    	PatternMatchingWithSuffixArray(s , t , order);
    }
    for(auto i: ans) cout<<i<<" ";
    return 0;
}
