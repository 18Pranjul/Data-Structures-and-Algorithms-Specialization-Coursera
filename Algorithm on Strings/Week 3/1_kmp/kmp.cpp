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
#define MAXN 300005
void inout()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
}
vll lps;
void computeLPS(string &a)
{
    ll n = a.size() , len = 0 , i = 1;
    lps.resize(n + 5);
    lps[0] = 0;
    while(i < n)
    {
        if(a[i] == a[len]) len++ , lps[i] = len , i++;
        else
        {
            if(len) len = lps[len - 1];
            else lps[i] = len , i++;
        }
    }
}
void KMP(string &a , string &b)
{
    ll m = a.size() , n = b.size() , i = 0 , j = 0;
    computeLPS(a);
    while(i < n)
    {
        if(a[j] == b[i]) i++ , j++;
        else 
        {
            if(j) j = lps[j - 1];
            else i++;
        }
        if(j == m) cout<<i-j<<" " , j = lps[j - 1];
    }
}
int main() 
{
    // inout();
    string a , b;
    cin>>a>>b;
    KMP(a , b);
    return 0;
}
