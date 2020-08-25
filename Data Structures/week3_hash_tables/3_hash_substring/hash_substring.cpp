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
#define TEST ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll hsh(string s)
{
	ll x=1,i,h=0;
	for(i=0;i<s.size();i++)
	{
	    h=((h+s[i]*x)%MOD);
	    x=(x*263)%MOD;
	}
	return h;
}
int main() 
{
	fast_io;
	string p,t;
	cin>>p>>t;
	ll i,h[t.size()+5],d=t.size()-p.size();
	h[d+1]=hsh(p);
	h[d]=hsh(t.substr(d));
	ll z=1;
	for(i=1;i<=p.size();i++) z=(z*263)%MOD;
	for(i=d-1;i>=0;i--)  h[i]=(h[i+1]*263-(z*t[i+p.size()])%MOD+t[i]+MOD)%MOD;
	ll f;
	for(i=0;i<=d;i++)
	{
	    if(h[i]==h[d+1])
	    {
	        f=1;
	        for(ll j=0;j<p.size();j++)
	        {
	            if(p[j]!=t[i+j])
	            {
	                f=0;
	                break;
	            }
	        }
	        if(f) cout<<i<<" ";
	    }
	}
	return 0;
}
