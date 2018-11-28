#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct node
{
	ll l,r,tag,sum[4];
};
ll gcd(ll x,ll y)
{
	return (y == 0) ? x : gcd(y,x % y);
}
ll sqr[N];
struct SegTree
{
	node tr[4 * N];
	node Merge(node a,node b)
	{
		node res;
		res.l = a.l; res.r = b.r;
		for (int i=1;i<=3;++i)
			res.sum[i] = a.sum[i] + b.sum[i];
		return res;
	}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	void Build(int k,ll l,int r)
	{
		tr[k].l = l; tr[k].r = r;
		tr[k].tag = 0;
		Clre(tr[k].sum);
		if (l == r)
			return;	
		int mid = (l + r) >> 1;
		Build(ls,l,mid);
		Build(rs,mid + 1,r);
	}
	//#define Get(l,r) (sqr[r] - sqr[l - 1])
	ll Get(ll l,int r)
	{
    	return 1LL*r*(r+1)*(2*r+1)/6LL-1LL*(l-1)*l*(2*l-1)/6LL;
	}
	void Update(int k,ll v)
	{
		ll len = tr[k].r - tr[k].l + 1;
		tr[k].sum[1] += (ll)len * v;                           //yici xiang
		tr[k].sum[2] += (ll)len * (ll)(tr[k].l + tr[k].r) / 2 * v; //
		tr[k].sum[3] += Get(tr[k].l,tr[k].r) * v;              //pingfangxiang
		tr[k].tag += v;
	}
	#undef Get
	void Pushdown(int k)
	{
		Update(ls,tr[k].tag); Update(rs,tr[k].tag);
		tr[k].tag = 0;
	}
	void Modify(int k,ll s,ll t,ll v)
	{
		ll l = tr[k].l,r = tr[k].r;
		if (s == l && t == r)
		{
			Update(k,v);
			return;	
		}
		if (tr[k].tag) Pushdown(k);
		ll mid = (l + r) >> 1;
		if (t <= mid) Modify(ls,s,t,v);
		else if (mid < s) Modify(rs,s,t,v);
		else Modify(ls,s,mid,v),Modify(rs,mid + 1,t,v);
		for (int i=1;i<=3;++i)
			tr[k].sum[i] = tr[ls].sum[i] + tr[rs].sum[i];
	}
	node Query(int k,ll s,ll t)
	{
		ll l = tr[k].l,r = tr[k].r;
		if (s == l && t == r)
			return tr[k];
		ll mid = (l + r) >> 1;
		if (tr[k].tag) Pushdown(k);
		if (t <= mid) return Query(ls,s,t);
		else if (mid < s) return Query(rs,s,t);
		else return Merge(Query(ls,s,mid),Query(rs,mid + 1,t));
	}
	ll Getans(ll s,ll t)
	{
		node res = Query(1,s,t - 1);
		return res.sum[1] * (t - s * t) + res.sum[2] * (s + t - 1) - res.sum[3];
	}
	
} T;
//Code

int n,m;
int main()
{
	n = read(); m = read();
	sqr[0] = 0;
	for (int i=1;i<=n;++i)
		sqr[i] = sqr[i - 1] + i * i;
	T.Build(1,1,n-1);
	char c;ll x,y,v;
	while (m--)
	{
		c = getchar();
		while(c != 'C' && c != 'Q') c = getchar();
		x = (ll)read(); y = (ll)read();
		if (x > y) swap(x,y);
		if (c == 'C')
			T.Modify(1,x,y - 1,(ll)read());
		else 
		{
			ll ans1 = T.Getans(x,y);
			ll ans2 = (ll)(y - x + 1) * (y - x) / 2;
			ll g = gcd(ans1,ans2);
			printf("%lld/%lld\n",ans1 / g,ans2 / g);
		}
	}
    return 0;
}
/*6 15
C 1 2 3
C 2 3 4
C 3 4 1
C 4 5 6
C 5 6 2

*/


