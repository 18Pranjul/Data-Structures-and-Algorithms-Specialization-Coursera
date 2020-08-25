#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll stack<ll>
#define qll queue<ll>
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
struct node
{
    char k;
    struct node* ch[27];
    node()
    {
        for(ll i=0;i<27;i++) ch[i]=NULL;
    }
};
void insert(struct node* root,string &a)
{
    ll i,j;
    struct node* tmp=root;
    for(i=0;i<a.size();i++)
    {
        if(tmp->ch[a[i]-'A']==NULL)
        {
            struct node* NEW=new node();
            NEW->k=a[i];
            tmp->ch[a[i]-'A']=NEW;
        }
        tmp=tmp->ch[a[i]-'A'];
    }
}
bool dfs(struct node* root,string &a,ll i)
{
    if(i<a.size())
    {
        if(root->ch[a[i]-'A']==NULL && root->ch[26]) return true;
        if(root->ch[a[i]-'A']) 
        {
            if(root->ch[a[i]-'A']->ch[26]) return true;
            return dfs(root->ch[a[i]-'A'],a,i+1);
        }
        return false;
    }
    if(root->ch[26]) return true;
    return false;
}
int main() 
{
	fast_io;
	struct node* root;
	root=new node();
	ll n;
	string txt;
	cin>>txt;
	cin>>n;
	string a;
	for(ll i=0;i<n;i++) 
	{
	    cin>>a;
	    a.pb('A'+26);
	    insert(root,a);
	}
	for(ll i=0;i<txt.size();i++)
	{
	    if(dfs(root,txt,i)) cout<<i<<" ";
	}
	return 0;
}
