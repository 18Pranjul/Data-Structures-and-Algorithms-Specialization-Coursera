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
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
struct node
{
    ll key,left,right;
};
ll c=1;
void iscorrect(node a[],ll root,ll l,ll r)
{
    if(!(a[root].key>l && a[root].key<r)) c=0;
    if(a[root].left!=-1) iscorrect(a,a[root].left,l,a[root].key);
    if(a[root].right!=-1) iscorrect(a,a[root].right,a[root].key,r);
}
int main() 
{
	fast_io;
	ll n,i;
	cin>>n;
	node nd[n+5];
	for(i=0;i<n;i++) cin>>nd[i].key>>nd[i].left>>nd[i].right;
	if(n==0) cout<<"CORRECT";
	else
	{
	    iscorrect(nd,0,-MAX,MAX);
	    cout<<(c?"CORRECT":"INCORRECT");
	}
	return 0;
}
