#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
bool cmp(string s1,string s2)
{
	string a=s1.append(s2);
	string b=s2.append(s1);
	return a.compare(b)>0?true:false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i;
	string k[101];
	cin>>n;
	for(i=0;i<n;i++) cin>>k[i];
	sort(k,k+n,cmp);
	for(i=0;i<n;i++) cout<<k[i];
	return 0;
}
