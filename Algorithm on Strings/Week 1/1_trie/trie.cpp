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
ll t=0;
struct node
{
    char k;
    ll val;
    struct node* ch[26];
    node()
    {
        for(ll i=0;i<26;i++) ch[i]=NULL;
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
            NEW->val=t++;
            tmp->ch[a[i]-'A']=NEW;
        }
        tmp=tmp->ch[a[i]-'A'];
    }
}
void dfs(struct node* root)
{
    ll i;
    for(i=0;i<26;i++)
    {
        if(root->ch[i]!=NULL)
        {
            cout<<root->val<<"->"<<root->ch[i]->val<<":"<<root->ch[i]->k<<ln;
            dfs(root->ch[i]);
        }
    }
}
int main() 
{
	fast_io;
	struct node* root;
	root=new node();
	root->val=t++;
	ll n;
	cin>>n;
	string a;
	for(ll i=0;i<n;i++) 
	{
	    cin>>a;
	    insert(root,a);
	}
	dfs(root);
	return 0;
}
