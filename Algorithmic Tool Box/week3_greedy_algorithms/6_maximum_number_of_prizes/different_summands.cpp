#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <ll> v;
	v.push_back(0);
	ll n,i=1;
	cin>>n;
	while(n>=i)
	{
		v.push_back(i);
		n-=i;
		i++;
	}
	v[i-1]+=n;
	cout<<v.size()-1<<"\n";
	for(i=1;i<v.size();i++)
	 cout<<v[i]<<" ";
	return 0;
}
