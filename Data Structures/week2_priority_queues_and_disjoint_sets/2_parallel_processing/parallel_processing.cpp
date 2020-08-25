#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
struct job
{
    ll a,b;
};
void siftup(job k[],ll i)
{
    ll max=i,p=(i-1)/2;
    if(p>=0 && (k[p].b>k[max].b || (k[p].b==k[max].b and k[p].a>k[max].a))) max=p;
    if(max-i)
    {
        swap(k[p],k[i]);
        siftup(k,p);
    }
}
void siftdown(job k[],ll n,ll i)
{
    ll min=i,l=2*i+1,r=l+1;
    if(l<n && (k[l].b<k[min].b || (k[l].b==k[min].b && k[l].a<k[min].a))) min=l;
    if(r<n && (k[r].b<k[min].b || (k[r].b==k[min].b && k[r].a<k[min].a))) min=r;
    if(min-i)
    {
        swap(k[min],k[i]);
        siftdown(k,n,min);
    }
}
int main()
{
    ll n,m,i,a[100005];
	cin>>n>>m;
	for(i=0;i<m;i++) cin>>a[i];
	job k[100005];
	for(i=0;i<n;i++)
	{
	    k[i].a=i;
	    k[i].b=0;
	}
	for(i=0;i<m;i++)
	{
	    cout<<k[0].a<<" "<<k[0].b<<ln;
	    swap(k[0],k[n-1]);
	    k[n-1].b+=a[i];
	    siftdown(k,n-1,0);
	    siftup(k,n-1);
	}
	return 0;
}
