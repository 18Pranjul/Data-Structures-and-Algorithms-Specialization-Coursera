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
ll hsh(string s,ll m)
{
	ll x=1,i,h=0;
	for(i=0;i<s.size();i++)
	{
	    h=((h+s[i]*x)%MOD);
	    x=(x*263)%MOD;
	}
	return h%m;
}
int main()
{
	fast_io;
	ll m,n,i,h,num;
	string op,name;
	map <ll,vector<string>> dir;
	cin>>m>>n;
	while(n--)
	{
		cin>>op;
		if(op=="check")
		{
		    cin>>num;
		    for(i=dir[num].size()-1;i>=0;i--)
		     cout<<dir[num][i]<<" ";
		    cout<<ln;
		}
		else
		{
		    cin>>name;
		    h=hsh(name,m);
		    if(op=="add")
		    {
			    ll f=0;
			    for(i=0;i<dir[h].size();i++)
			    {
				    if(dir[h][i]==name)
			    	{
					    f=1;
					    break;
				    }
			    }
			    if(!f) dir[h].pb(name);
		    }
		    else if(op=="del")
		    {
			    for(i=0;i<dir[h].size();i++)
			    {
				    if(dir[h][i]==name)
				    {
					    dir[h].erase(dir[h].begin()+i);
					    break;
				    }
			    }
		    }
		    else
		    {
			    ll f=0;
			    for(i=0;i<dir[h].size();i++)
			    {
				    if(dir[h][i]==name)
				    {
					    cout<<"yes";
					    f=1;
					    break;
				    }
			    }
			    if(!f) cout<<"no";
			    cout<<ln;
		    }
	    }
	}
	return 0;
}
