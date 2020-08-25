#include <iostream>
#include <deque>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,a[100005],i;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	cin>>m;
	deque <int> q;
	for(i=0;i<m;i++)
	{
	    while(!q.empty() && a[i]>=a[q.back()])
	     q.pop_back();
	    q.push_back(i);
	}
	cout<<a[q.front()]<<" ";
	for(;i<n;i++)
	{
	    while(!q.empty() && q.front()<=i-m)
	     q.pop_front();
	    while(!q.empty() && a[i]>=a[q.back()])
	     q.pop_back();
	    q.push_back(i);
	    cout<<a[q.front()]<<" ";
	}
	return 0;
}
