#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int min(int a,int b,int c)
{
	if(a<=b && a<=c)
	 return a;
	if(b<=c && b<=a)
	 return b;
	return c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1,s2;
	int m,n,dp[101][101],i,j;
	cin>>s1>>s2;
	m=s1.length();
	n=s2.length();
	for(i=0;i<=m;i++)
	 dp[i][0]=i;
	for(i=0;i<=n;i++)
	 dp[0][i]=i;
	for(i=1;i<=m;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	        if(s1[i-1]==s2[j-1])
	         dp[i][j]=dp[i-1][j-1];
	        else
	         dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
	    }
	}
	cout<<dp[m][n];
	return 0;
}
