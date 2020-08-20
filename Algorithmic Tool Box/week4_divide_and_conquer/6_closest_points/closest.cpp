#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ld long double
#define MOD 1000000007
struct point
{
    ld x;
    ld y;
};
bool cmpx(point p1,point p2)
{
    return p1.x<p2.x;
}
bool cmpy(point p1,point p2)
{
    return p1.y<p2.y;
}
ld dist(point p1,point p2)
{
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
}
ld min(ld a,ld b)
{
    return a<b?a:b;
}
ld ans(point p[],int l,int r)
{
    int i,j;
    ld mn=DBL_MAX;
    for(i=l;i<r;i++)
     for(j=i+1;j<=r;j++)
      mn=min(mn,dist(p[i],p[j]));
    return mn;
}
ld minDist1(point strip[],int l,ld d)
{
    ld mn=d;
    int i,j;
    sort(strip,strip+l,cmpy);
    for(i=0;i<l-1;i++)
     for(j=i+1;j<l && (strip[j].y-strip[i].y)<mn;j++)
      mn=min(mn,dist(strip[i],strip[j]));
    return mn;
}
ld minDist(point p[],int l,int r)
{
    if(r-l+1<=3)
     return ans(p,l,r);
    int i,j=0;
    int mid=(l+r)/2;
    ld dl=minDist(p,l,mid);
    ld dr=minDist(p,mid+1,r);
    ld d=min(dl,dr);
    point strip[r-l+5];
    for(i=l;i<=r;i++)
     if(abs(p[i].x-p[mid].x)<d)
      strip[j++]=p[i];
    return min(d,minDist1(strip,j,d));
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i;
	cin>>n;
	point p[100005];
	for(i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	sort(p,p+n,cmpx);
	cout<<fixed<<setprecision(3)<<minDist(p,0,n-1);
	return 0;
}
