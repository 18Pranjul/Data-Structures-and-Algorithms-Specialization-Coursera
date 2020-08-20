#include <iostream>
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
	int n,i,a[1000];
	a[1]=1;
	a[2]=2;
	a[3]=1;
	a[4]=1;
	for(i=5;i<=1000;i++)
	 a[i]=min(a[i-4],a[i-3],a[i-1])+1;
	cin>>n;
	cout<<a[n];
	return 0;
}
