#include <iostream>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
ll dp[101][101][101];
ll max(ll a,ll b)
{
    if(a>b)
     return a;
    return b;
}
ll max1(ll a,ll b,ll c)
{
	return max(a,max(b,c));
}
void init()
{
    ll i,j,k;
    for(i=0;i<101;i++)
     for(j=0;j<101;j++)
      for(k=0;k<101;k++)
       dp[i][j][k]=0;
}
void DP(ll a[],ll b[],ll c[],ll m,ll n,ll k)
{
    init();
    ll i,j,l;
	for(i=0;i<=m;i++)
	{
	    for(j=0;j<=n;j++)
	    {
	        for(l=0;l<=k;l++)
	        {
	            if(i==0 || j==0 || l==0)
	             dp[i][j][k]=0;
	            else if(a[i-1]==b[j-1] && a[i-1]==c[l-1])
	             dp[i][j][l]=dp[i-1][j-1][l-1]+1;
	            else
	             dp[i][j][l]=max1(dp[i-1][j][l],dp[i][j-1][l],dp[i][j][l-1]);
	        }
	    }
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll m,n,k,a[101],b[101],c[101],i,j,l=0,d[101];
	cin>>m;
	for(i=0;i<m;i++) cin>>a[i];
	cin>>n;
	for(i=0;i<n;i++) cin>>b[i];
	cin>>k;
	for(i=0;i<k;i++) cin>>c[i];
	DP(a,b,c,m,n,k);
	cout<<dp[m][n][k];
	return 0;
}
