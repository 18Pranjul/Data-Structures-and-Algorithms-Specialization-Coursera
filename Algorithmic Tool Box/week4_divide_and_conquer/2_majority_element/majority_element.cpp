#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
ll maj(ll a[],ll n)
{
	ll i;
	for(i=0;i<n/2+n%2;i++)
	 if(a[i]==a[i+n/2])
	  return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,i,a[100001];
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<maj(a,n);
	return 0;
}
