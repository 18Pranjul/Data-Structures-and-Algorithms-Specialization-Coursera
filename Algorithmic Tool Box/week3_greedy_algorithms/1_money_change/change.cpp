#include <iostream>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,a,b;
	cin>>m;
	a=m/10;
	m-=(a*10);
	b=m/5;
	m-=(b*5);
	cout<<a+b+m;
	return 0;
}
