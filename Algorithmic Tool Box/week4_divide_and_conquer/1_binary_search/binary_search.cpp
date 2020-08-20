#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
ll bin(ll a[],ll l,ll r,ll x)
{
	if(l>r)
	 return -1;
	ll m=(l+r)/2;
	if(a[m]==x)
	 return m;
	if(a[m]>x)
	 bin(a,l,m-1,x);
	else
	 bin(a,m+1,r,x);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k,b,a[100001],i;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	cin>>k;
	sort(a,a+n);
	for(i=0;i<k;i++)
	{
		cin>>b;
		cout<<bin(a,0,n-1,b)<<" ";
	}
	return 0;
}
