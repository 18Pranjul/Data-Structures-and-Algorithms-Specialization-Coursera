#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
int main() 
{
	int W,n,i,j;
	int w[305];
	cin>>W>>n;
	for(i=1;i<=n;i++) cin>>w[i];
	vector <int> dp[301];
	sort(w+1,w+n+1);
	for(i=0;i<=n;i++)
	{
	    for(j=0;j<=W;j++)
	    {
	        if(i==0 || j==0)
	        {
	            dp[i].push_back(0);
	            continue;
	        }
	        dp[i].push_back(dp[i-1][j]);
	        if(w[i]<=j)
	         dp[i][j]=max(w[i]+dp[i-1][j-w[i]],dp[i][j]);
	    }
	}
	cout<<dp[n][W];
	return 0;
}
