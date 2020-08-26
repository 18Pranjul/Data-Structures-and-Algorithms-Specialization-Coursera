#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define vll vector<ll>
#define vs vector<string>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define vvpll vector<vpll>
#define mp make_pair
#define f first
#define s second
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define Test ll T;cin>>T; while(T--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define init(x,n,v) for(ll i=0;i<=n;i++) x[i]=v;
#define all(x) x.begin(),x.end()
#define pi 3.14159265358979323846
#define MOD 1000000007
#define MAX 2000000000000000000
#define MAXN 100005
void inout()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
}
struct SuffixTreeNode
{
	SuffixTreeNode *parent{nullptr};
	map <char , SuffixTreeNode*> children;
	ll stringDepth{0} , edgeStart{-1} , edgeEnd{-1};
	SuffixTreeNode(SuffixTreeNode *a , ll b , ll c , ll d)
	{
		parent = a;
		stringDepth = b , edgeStart = c , edgeEnd = d;
	}
};
SuffixTreeNode *CreateNewLeaf(SuffixTreeNode *node , string &s , ll suffix)
{
	SuffixTreeNode *leaf = new SuffixTreeNode(node , s.size() - suffix , suffix + node->stringDepth , s.size() - 1);
	node->children[s[leaf->edgeStart]] = leaf;
	return leaf;
}
SuffixTreeNode *BreakEdge(SuffixTreeNode *node , string &s , ll start , ll offset)
{
	char startChar = s[start] , midChar = s[start + offset];
	SuffixTreeNode *midNode = new SuffixTreeNode(node , node->stringDepth + offset , start , start + offset - 1);
	midNode->children[midChar] = node->children[startChar];
	node->children[startChar]->parent = midNode;
	node->children[startChar]->edgeStart += offset;
	node->children[startChar] = midNode;
	return midNode;
}
SuffixTreeNode *STFromSA(string &s , vll &order , vll &lcp)
{
	SuffixTreeNode *root = new SuffixTreeNode(NULL , 0 , -1 , -1);
	SuffixTreeNode *curNode = root;
	ll lcpPrev = 0 , i , n = s.size();
	for(i = 0 ; i < n ; i++)
	{
		ll suffix = order[i];
		while(curNode->stringDepth > lcpPrev) curNode = curNode->parent;
		if(curNode->stringDepth == lcpPrev) curNode = CreateNewLeaf(curNode , s , suffix);
		else
		{
			ll edgeStart = order[i - 1] + curNode->stringDepth;
			ll offset = lcpPrev - curNode->stringDepth;
			SuffixTreeNode *midNode = BreakEdge(curNode , s , edgeStart , offset);
			curNode = CreateNewLeaf(midNode , s , suffix);
		}
		if(i < n - 1) lcpPrev = lcp[i];
	}
	return root;
} 
void dfs(SuffixTreeNode *curNode)
{
	if(curNode->edgeStart != -1 && curNode->edgeEnd != -1)
	 cout<<curNode->edgeStart<<" "<<curNode->edgeEnd + 1<<ln;
	for(auto k: curNode->children) dfs(k.s);
}
int main() 
{
    //inout();
    string s;
    cin>>s;
    ll n = s.size();
    vll order(n) , lcp(n - 1);
    for(auto &i: order) cin>>i;
    for(auto &i: lcp) cin>>i;
    SuffixTreeNode *root = STFromSA(s , order , lcp);
	cout<<s<<ln;
	dfs(root);
    return 0;
}
