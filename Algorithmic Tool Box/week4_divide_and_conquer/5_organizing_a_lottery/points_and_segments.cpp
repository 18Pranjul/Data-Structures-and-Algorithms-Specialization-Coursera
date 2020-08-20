#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
struct st
{
	ll n;
	ll pos;
	ll pos1;
};
bool cmp(st s1,st s2)
{
	if(s1.n==s2.n)
	 return s1.pos<s2.pos;
	return s1.n<s2.n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll s,p,i,a,b,j,k,l,r;
	cin>>s>>p;
	st seg[(s*2)+p];
	ll x,ans[p+1];
	j=0;
	for(i=0;i<s;i++)
	{
		cin>>a>>b;
		seg[j].n=a;
		seg[j++].pos=-1;
		seg[j].n=b;
		seg[j++].pos=1;
	}
	i=0;
	for(i=0;i<p;i++)
	{
		cin>>x;
		seg[j].n=x;
		seg[j].pos=0;
		seg[j++].pos1=i;
	}
	sort(seg,seg+j,cmp);
	k=l=r=0;
	while(k<j)
	{
		if(seg[k].pos==0)
		 ans[seg[k].pos1]=l-r;
		if(seg[k].pos==-1)
		 l++;
		if(seg[k].pos==1)
		 r++;
		k++;
	}
	for(i=0;i<p;i++)
	 cout<<ans[i]<<" ";
	return 0;
}
