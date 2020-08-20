#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
struct tslot
{
	ll a;
	ll b;
};
bool cmp(tslot t1,tslot t2)
{
	return t1.b<t2.b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,i,s=0,p[101];
	tslot t[101];
	cin>>n;
	for(i=0;i<n;i++) 
	 cin>>t[i].a>>t[i].b;
	sort(t,t+n,cmp);
	i=0;
	while(i<n)
	{
		p[s]=t[i].b;
		while(i<n && p[s]>=t[i].a && p[s]<=t[i].b)
		 i++;
		s++;
	}
	cout<<s<<"\n";
	for(i=0;i<s;i++) cout<<p[i]<<" ";
	return 0;
}
