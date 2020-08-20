#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
struct bag
{
	ll w;
	ll v;
	double r;
};
bool cmp(bag b1,bag b2)
{
	return b1.r>b2.r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,W,i,a;
	double v=0.0;
	bag b[1001];
	cin>>n>>W;
	for(i=0;i<n;i++)
	{
		cin>>b[i].v>>b[i].w;
		b[i].r=(b[i].v*(1.0))/b[i].w;
	}
	sort(b,b+n,cmp);
	i=0;
	while(W>0 && i<n)
	{
		a=min(b[i].w,W);
		v+=(a*b[i].v*(1.0))/b[i].w;
		W-=a;
		i++;
	}
	cout<<fixed<<setprecision(3)<<v;
	return 0;
}
