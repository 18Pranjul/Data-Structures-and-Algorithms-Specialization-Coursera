#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
struct piv
{
	ll m1;
	ll m2;
};
void swap(ll a[],ll i,ll j)
{
	ll t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void part_r(ll a[],ll l,ll r)
{
	ll x=l+rand()%(r-l);
	swap(a,l,x);
}
piv part(ll a[],ll l,ll r)
{
	part_r(a,l,r);
	ll i,j=l,k=l,c=0;
	piv p;
	for(i=l+1;i<=r;i++)
	{
		if(a[i]==a[l])
		{
			k++;
			j++;
			swap(a,j,i);
			swap(a,k,j);
		}
		else if(a[i]<a[l])
		{
			j++;
			swap(a,i,j);
		}
	}
	for(i=l;i<=k;i++)
	{
		swap(a,i,j-c);
		c++;
	}
	k=j-c+1;
	p.m1=k;
	p.m2=j;
	return p;
	
}
void qsort(ll a[],ll l,ll r)
{
	if(l<r)
	{
		piv m=part(a,l,r);
		qsort(a,l,m.m1-1);
		qsort(a,m.m2+1,r);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,a[100001],i;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	qsort(a,0,n-1);
	for(i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
