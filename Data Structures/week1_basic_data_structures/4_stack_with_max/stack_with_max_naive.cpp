#include <iostream>
#include <stack>
#include <string>
using namespace std;
typedef long long int ll;
#define MOD 1000000007;
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,a;
	string s;
	stack <ll> st;
	stack <ll> st_max;
	cin>>n;
	while(n--)
	{
	    cin>>s;
	    if(s.at(0)=='p' && s.at(1)=='u')
	    {
	        cin>>a;
	        st.push(a);
	        if(st_max.empty())
	         st_max.push(a);
	        else if(st_max.top()<a)
	         st_max.push(a);
	        else
	         st_max.push(st_max.top());
	    }
	    else if(s.at(0)=='m')
	    {
	        cout<<st_max.top()<<"\n";
	    }
	    else
	    {
	         st.pop();
	         st_max.pop();
	    }
	}
	return 0;
}
