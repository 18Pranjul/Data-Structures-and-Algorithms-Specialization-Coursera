#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d,l,n,x[100005],i,N=0;
	cin>>d>>l>>n;
	x[0]=0;
	x[n+1]=d;
	for(i=1;i<=n;i++)
	 cin>>x[i];
	sort(x,x+n+2);
	i=0;
	while(i<=n)
	{
		int k=i;
		while(i<=n+1 && x[i]-x[k]<=l)
		 i++;
		i--;
		if(k==i)
		{
			N=-1;
			break;
		}
		else
		 if(i<=n)
		  N++;
	}
	cout<<N;
	return 0;
}
