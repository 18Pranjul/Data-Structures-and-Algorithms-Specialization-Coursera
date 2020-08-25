#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
vector <pair<ll,ll>> v;
ll c=0;
void heapify(ll a[],ll n,ll i)
{
    ll min=i,l=2*i+1,r=2*i+2;
    if(l<n && a[min]>a[l])
     min=l;
    if(r<n && a[min]>a[r])
     min=r;
    if(min!=i)
    {
        swap(a[i],a[min]);
        v.push_back({i,min});
        c++;
        heapify(a,n,min);
    }
}
void minheap(ll a[],ll n)
{
    ll i;
    for(i=(n/2)-1;i>=0;i--)
     heapify(a,n,i);
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,a[100005],i;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	minheap(a,n);
	cout<<c;
	for(i=0;i<c;i++) cout<<ln<<v[i].first<<" "<<v[i].second;
	return 0;
}
