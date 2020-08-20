#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int max(int a,int b)
{
	if(a>=b)
	 return a;
	return b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll m,n,a[101],b[101],dp[101][101],i,j;
	cin>>m;
	for(i=0;i<m;i++) cin>>a[i];
	cin>>n;
	for(i=0;i<n;i++) cin>>b[i];
	for(i=0;i<=m;i++)
	 dp[i][0]=0;
	for(i=0;i<=n;i++)
	 dp[0][i]=0;
	for(i=1;i<=m;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	        if(a[i-1]==b[j-1])
	         dp[i][j]=dp[i-1][j-1]+1;
	        else
	         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	    }
	}
	cout<<dp[m][n];
	return 0;
}
