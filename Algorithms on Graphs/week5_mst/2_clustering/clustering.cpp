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
struct edge
{
    ll u,v;
    double d;
};
struct SET
{
    ll p;
    ll r;
};
double dist(pll p1,pll p2)
{
    double d=sqrt(pow(p1.f-p2.f,2)+pow(p1.s-p2.s,2))*1.0;
    return d;
}
bool cmp(edge e1,edge e2)
{
    return e1.d<e2.d;
}
ll root(SET s[],ll a)
{
    if(s[a].p!=a)
     s[a].p=root(s,s[a].p);
    return s[a].p;
}
void Union(SET s[],ll a,ll b)
{
    if(s[a].r<s[b].r) s[a].p=b;
    else if(s[a].r>s[b].r) s[b].p=a;
    else s[a].p=b,s[b].r++;
}
void kruskal(edge e[],ll k,ll n,vll &v)
{
    ll i;
    SET s[n+5];
    for(i=0;i<n;i++) s[i].p=i,s[i].r=0;
    for(i=0;i<k;i++)
    {
        ll x=root(s,e[i].u);
        ll y=root(s,e[i].v);
        if(x!=y)
        {
            v.pb(i);
            Union(s,x,y);
        }
    }
}
int main() 
{
	fast_io;
	ll n,i,j,k,m;
	cin>>n;
	pll p[n+5];
	for(i=0;i<n;i++) cin>>p[i].f>>p[i].s;
	cin>>m;
	edge e[n*n+5];
	k=0;
	for(i=0;i<n;i++)
	 for(j=i+1;j<n;j++)
	 {
	     e[k].u=i;
	     e[k].v=j;
	     e[k++].d=dist(p[i],p[j]);
	 }
	sort(e,e+k,cmp);
	vll v;
	kruskal(e,k,n,v);
	double ans=0.0;
	//for(i=0;i<m;i++) ans+=e[v[i]].d;
	cout<<fixed<<setprecision(7)<<e[v[n-m]].d;
	return 0;
}
