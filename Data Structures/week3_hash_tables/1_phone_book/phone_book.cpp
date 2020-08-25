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
#define MOD 1000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define TEST ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll hsh(ll n)
{
	ll a=100007,b=111111;
	ll h=(a*n+b)%MOD;
	return h;
}
int main()
{
	fast_io;
	ll n,i,h,num;
	string op,name;
	map <ll,vector<pair<ll,string>>> dir;
	cin>>n;
	while(n--)
	{
		cin>>op>>num;
		h=hsh(num);
		if(op=="add")
		{
			cin>>name;
			ll f=0;
			for(i=0;i<dir[h].size();i++)
			{
				if(dir[h][i].f==num)
				{
					dir[h][i].s=name;
					f=1;
					break;
				}
			}
			if(!f) dir[h].pb(mp(num,name));
		}
		else if(op=="del")
		{
			for(i=0;i<dir[h].size();i++)
			{
				if(dir[h][i].f==num)
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
				if(dir[h][i].f==num)
				{
					cout<<dir[h][i].s<<ln;
					f=1;
					break;
				}
			}
			if(!f) cout<<"not found\n";
		}
	}
	return 0;
}
