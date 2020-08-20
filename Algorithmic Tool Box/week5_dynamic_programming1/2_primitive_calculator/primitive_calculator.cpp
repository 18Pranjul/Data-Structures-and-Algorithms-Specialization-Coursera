#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,a[1000001];
	cin>>n;
	stack <int> st;
	a[1]=0;
	a[2]=1;
	a[3]=1;
	for(i=4;i<=1000000;i++)
	{
		a[i]=a[i-1]+1;
		if(i%2==0)
		 a[i]=min(a[i/2]+1,a[i]);
		if(i%3==0)
		 a[i]=min(a[i/3]+1,a[i]);
	}
	for(i=n;i>1;)
	{
		st.push(i);
		if(a[i-1]+1==a[i])
		 i-=1;
		else if(i%2==0 && a[i/2]+1==a[i])
		 i/=2;
		else if(i%3==0 && a[i/3]+1==a[i])
		 i/=3;
	}
	st.push(1);
	cout<<a[n]<<"\n";
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
