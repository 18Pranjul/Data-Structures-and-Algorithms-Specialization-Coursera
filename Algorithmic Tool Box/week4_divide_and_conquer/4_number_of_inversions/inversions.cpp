#include <iostream>
using namespace std;
typedef long long int ll;
ll c;
void mer(ll a[],ll n,ll l,ll m,ll r)
{
    ll i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    ll L[n1],R[n2];
    for(i=0;i<n1;i++)
     L[i]=a[l+i];
    for(j=0;j<n2;j++)
     R[j]=a[m+j+1];
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
         a[k++]=L[i++];
        else
        {
            a[k++]=R[j++];
            c+=(m+j+1-k);
        }
    }
    while(i<n1)
     a[k++]=L[i++];
    while(j<n2)
     a[k++]=R[j++];
}
void msort(ll a[],ll n,ll l,ll r)
{
    if(l<r)
    {
        ll m=l+(r-l)/2;
        msort(a,n,l,m);
        msort(a,n,m+1,r);
        mer(a,n,l,m,r);
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a[100001],i;
    cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
    c=0;
    msort(a,n,0,n-1);
    cout<<c;
	return 0;
}

