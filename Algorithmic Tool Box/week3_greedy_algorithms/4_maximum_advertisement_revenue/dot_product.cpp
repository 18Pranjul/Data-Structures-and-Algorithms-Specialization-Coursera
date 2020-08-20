#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,a[1005],b[1005],i,sum=0;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	for(i=0;i<n;i++) sum+=(a[i]*b[i]);
	cout<<sum;
	return 0;
}
