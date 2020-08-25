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
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
struct node
{
    ll key,left,right;
};
void inorder(node nd[],ll n,ll root)
{
    if(nd[root].left!=-1) inorder(nd,n,nd[root].left);
    cout<<nd[root].key<<" ";
    if(nd[root].right!=-1) inorder(nd,n,nd[root].right);
}
void preorder(node nd[],ll n,ll root)
{
    cout<<nd[root].key<<" ";
    if(nd[root].left!=-1) preorder(nd,n,nd[root].left);
    if(nd[root].right!=-1) preorder(nd,n,nd[root].right);
}
void postorder(node nd[],ll n,ll root)
{
    if(nd[root].left!=-1) postorder(nd,n,nd[root].left);
    if(nd[root].right!=-1) postorder(nd,n,nd[root].right);
    cout<<nd[root].key<<" ";
}
int main() 
{
	fast_io;
	ll n,i;
	cin>>n;
	node nd[n+5];
	for(i=0;i<n;i++) cin>>nd[i].key>>nd[i].left>>nd[i].right;
	inorder(nd,n,0);
	cout<<ln;
	preorder(nd,n,0);
	cout<<ln;
	postorder(nd,n,0);
	return 0;
}
