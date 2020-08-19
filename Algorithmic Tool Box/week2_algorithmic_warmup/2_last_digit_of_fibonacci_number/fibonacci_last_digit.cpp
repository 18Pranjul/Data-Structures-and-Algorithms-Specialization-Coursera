#include <iostream>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,i,f=0,s=1,t;
	cin>>n;
	if(n<=1)
	 cout<<n;
	else
	{
		for(i=2;i<=n;i++)
		{
			t=(f+s)%10;
			f=s;
			s=t;
		}
		cout<<t;
	}
	return 0;
}
