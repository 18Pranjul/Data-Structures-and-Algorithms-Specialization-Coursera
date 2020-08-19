#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,i,a[100005],m1;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	m1=a[n-1]*a[n-2];
	cout<<m1;
	return 0;
}
