#include <iostream>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(b==0)
	 return a;
	return gcd(b,a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
