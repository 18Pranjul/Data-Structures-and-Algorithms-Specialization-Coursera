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
void SortCharacters(string &s , vll &order)
{
    ll n = s.size() , i;
    vll count(26);
    order[0] = n - 1;
    for(i = 0 ; i < n - 1 ; i++) count[s[i] - 'A']++;
    for(i = 1 ; i < 26 ; i++) count[i] += count[i - 1];
    for(i = n - 2 ; i >= 0 ; i--) order[count[s[i] - 'A']--] = i;
}
void ComputeCharClasses(string &s , vll &order , vll &Class)
{
	ll n = s.size() , i;
	Class[n - 1] = 0;
	for(i = 1 ; i < n ; i++)
	{
		Class[order[i]] = Class[order[i - 1]];
		if(s[order[i]] != s[order[i - 1]]) Class[order[i]]++;
	}
}
void SortDoubled(string &s , ll l , vll &order , vll &Class)
{
	ll n = s.size() , i;
	vll count(n) , newOrder(n);
	for(i = 0 ; i < n ; i++) count[Class[i]]++;
	for(i = 1 ; i < n ; i++) count[i] += count[i - 1];
	for(i = n - 1 ; i >= 0 ; i--)
	{
		ll st = (order[i] - l + n) % n;
		newOrder[--count[Class[st]]] = st;
	}
	swap(order , newOrder);
}
void UpdateClasses(vll &order , vll &Class , ll l)
{
	ll n = order.size() , i;
	vll newClass(n);
	newClass[order[0]] = 0;
	for(i = 1 ; i < n ; i++)
	{
		ll cur = order[i] , prev = order[i - 1] , mid = (cur + l) % n , midPrev = (prev + l) % n;
		newClass[cur] = newClass[prev];
		if(Class[cur] != Class[prev] || Class[mid] != Class[midPrev]) newClass[cur]++; 
	}
	swap(Class , newClass);
}
ll LCPofSuffixes(string &s , ll i , ll j , ll equal)
{
	ll lcp = max(0ll , equal) , n = s.size();
	while(i + lcp < n && j + lcp < n && s[i + lcp] == s[j + lcp]) lcp++;
	return lcp;
}
vll InvertSuffixArray(vll &order)
{
	ll n = order.size() , i;
	vll pos(n);
	for(i = 0 ; i < n ; i++) pos[order[i]] = i;
	return pos;
}
vll ComputeLCPArray(string &s , vll &order)
{
	ll n = s.size() , lcp = 0;
	vll lcpArray(n - 1) , posInOrder = InvertSuffixArray(order);
	ll suffix = order[0] , i;
	for(i = 0 ; i < n ; i++)
	{
		ll orderIndex = posInOrder[suffix];
		if(orderIndex == n - 1)
		{
			lcp = 0;
			suffix = (suffix + 1) % n;
			continue;
		}
		ll nextSuffix = order[orderIndex + 1];
		lcp = LCPofSuffixes(s , suffix , nextSuffix , lcp - 1);
		lcpArray[orderIndex] = lcp;
		suffix = (suffix + 1) % n;
	}
	return lcpArray;
}
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
void dfs(string &s , SuffixTreeNode *curNode)
{
	for(auto k: curNode->children) 
	{
		cout<<s.substr(k.s->edgeStart , k.s->edgeEnd - k.s->edgeStart + 1)<<ln;
		dfs(s , k.s);
	}
}
int main() 
{
    //inout();
    string s;
    cin>>s;
    ll n = s.size() , l = 1;
    vll order(n) , Class(n) , lcp(n - 1);
    SortCharacters(s , order);
    ComputeCharClasses(s , order , Class);
    while(l < n)
    {
    	SortDoubled(s , l , order , Class);
    	UpdateClasses(order , Class , l);
	    l *= 2;
    }
    lcp = ComputeLCPArray(s , order);
    SuffixTreeNode *root = STFromSA(s , order , lcp);
	dfs(s , root);
    return 0;
}
