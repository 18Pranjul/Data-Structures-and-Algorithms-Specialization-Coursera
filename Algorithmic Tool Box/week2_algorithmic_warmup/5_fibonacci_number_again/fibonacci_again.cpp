#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,f=0,s=1,t,i,j=0,k;
	cin>>n>>m;
	vector <ll> v;
	v.push_back(0);
	v.push_back(1);
	if(n<=1)
	 cout<<n;
	else
	{
		for(i=2;;i++)
		{
			t=(f+s)%m;
			f=s;
			s=t;
			v.push_back(t%m);
			if(v[i]==v[j])
			{
				j++;
				if((i+1)/2==j && i%2==1)
				 break;
			}
			else
			 j=0;
		}
		cout<<"Period: "<<j<<endl;
		n%=j;
		cout<<v[n];
	}
	return 0;
}

