#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,f=0,s=1,t,sum=1,i,j=0,k;
	cin>>m>>n;
	vector <ll> v;
	v.push_back(0);
	v.push_back(1);
	for(i=2;;i++)
	{
		t=(f+s)%10;
		sum=(sum+t)%10;
		f=s;
		s=t;
		//cout<<sum<<endl;
		v.push_back(sum%10);
		if(v[i]==v[j])
		{
			j++;
			if((i+1)/2==j && i%2==1)
			 break;
		}
		else
		{
			j=0;
			if(v[i]==v[j])
			{
				j++;
			}
		}
	}
	//cout<<"Period: "<<j<<endl;
	n%=j;
	if(m==0)
	 cout<<v[n];
	else
	{
		m=(m-1)%j;
		cout<<(v[n]-v[m]>=0?v[n]-v[m]:10+v[n]-v[m]);
	}
	return 0;
}
