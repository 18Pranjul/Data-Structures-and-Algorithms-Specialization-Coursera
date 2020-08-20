#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
void init(vector <int> dp[],int n)
{
    int i;
    for(i=0;i<n;i++)
     dp[i].clear();
}
void update(vector <int> dp[],int n,int W,vector <int> w)
{
    int i,j;
    init(dp,n);
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
}
void neww(vector <int> dp[],int n,int W,vector <int> w)
{
    int i=n,j=W;
    while(dp[i][j]>0)
    {
        if(w[i]<=j && dp[i][j]!=dp[i-1][j])
        {
            w.erase(w.begin()+i);
            i--;
            j=j-w[i];
        }
        else
         i--;
    }
}
int main() 
{
	int n,i,j,sum=0,f;
	cin>>n;
    vector <int> dp[30],w;
    w.push_back(0);
	for(i=1;i<=n;i++)
	{
	    cin>>j;
	    w.push_back(j);
	    sum+=w[i];
	}
	if(n<3)
	 cout<<0;
	else if(sum%3!=0)
	 cout<<0;
	else
	{
	    f=1;
	    sort(w.begin()+1,w.begin()+n+1);
	    update(dp,n,sum/3,w);
	    if(dp[n][sum/3]!=sum/3)
	     f=0;
	    neww(dp,n,sum/3,w);
	    update(dp,n,sum/3,w);
	    if(dp[n][sum/3]!=sum/3)
	     f=0;
	    cout<<f;
	}
	return 0;
}
