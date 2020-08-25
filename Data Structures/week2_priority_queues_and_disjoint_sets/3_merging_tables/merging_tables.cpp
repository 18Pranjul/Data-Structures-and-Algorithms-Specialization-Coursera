#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
ll root(ll a,ll arr[])
{
    while(arr[a]!=a)
     arr[a]=arr[arr[a]] , a=arr[a];
    return a;
}
ll _union(ll c[],ll sz[],ll size[],ll a,ll b,ll max)
{
    a=root(a,c);
    b=root(b,c);
    if(a!=b)
    {
        if(size[a]>=size[b])
        {
            c[b]=a;
            size[a]+=size[b];
            sz[a]+=sz[b];
            if(max<sz[a]) max=sz[a];
        }
        else
        {
            c[a]=b; 
            size[b]+=size[a];
            sz[b]+=sz[a];
            if(max<sz[b]) max=sz[b];
        }
    }
    return max;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,size[100005],con[100005],sz[100005],i,max=0,q1,q2;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	    con[i]=i;
	    size[i]=1;
	}
	for(i=1;i<=n;i++)
	{
	    cin>>sz[i];
	    if(max<sz[i]) max=sz[i];
	}
	while(m--)
	{
	    cin>>q1>>q2;
	    max=_union(con,sz,size,q1,q2,max);
	    cout<<max<<ln;
	}
	return 0;
}
