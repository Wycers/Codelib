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
const int N = 5e4 + 10;
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
	int l, r, s, t, sz, mx;
};
struct Segment_tree
{
	node tr[4 * N], null;
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	node Merge(const node &a,const node &b)
	{
		node res;
		res.l = min(a.l, b.l); res.r = max(a.r, b.r);
		res.s = min(a.s, b.s); res.t = max(a.t, b.t);
		res.sz = a.sz + b.sz;
		res.mx = max(a.mx, b.mx);
		return res;
	}
	void Build(int k,int l,int r)
	{
		if (l == r)
		{
			tr[k].l = l; tr[k].r = r;
			tr[k].s = tr[k].t = read(); 
			tr[k].mx = read();
			tr[k].sz = 1;
			return;	
		}
		int mid = (l + r) >> 1;
		Build( ls, l, mid);
		Build( rs, mid + 1, r);
		tr[k] = Merge( tr[ls], tr[rs]);
	}
	node Query(int k,int s,int t)
	{
		if (tr[k].t < s || t < tr[k].s)
			return null;
		if (s <= tr[k].s && tr[k].t <= t)
			return tr[k];
		if (t <= tr[ls].t)
			return Query(ls, s, t);
		if (tr[rs].s <= s)
			return Query(rs, s, t);
		int mid = tr[ls].t;
		return Merge(Query(ls, s, mid), Query(rs, mid + 1, t));
	} 
	node Ask(int s,int t)
	{
		if (s > t) return null;
		else return Query(1, s, t);	
	}
} T;
//Code
int n;

int main()
{
	n = read();
	T.null = (node){Inf, -Inf, Inf, -Inf, 0, 0};
	T.Build(1, 1, n);
	node t1, t2, tx, ty;
	for (int i = 1, m = read(), x, y;i <= m; ++i)
	{
		x = read(); y = read(); 
		if (x > y)
		{
			puts("false");
			continue;
		}
		if (x == y)
		{
			puts("maybe");
			continue;
		}
		tx = T.Ask(x, x); ty = T.Ask(y, y);
		t1 = T.Ask(x, y); t2 = T.Ask(x + 1, y - 1);
		if (y - x + 1 == t1.sz && t2.mx < ty.mx && ty.mx <= tx.mx)
		{
			puts("true");
			continue;
		}
		if (tx.sz == 0 && ty.sz == 0)
		{
			puts("maybe");
			continue;
		}
		if (tx.sz == 0 || ty.sz == 0)
		{
			if (ty.sz == 0 && t2.mx < tx.mx)
			{
				puts("maybe");
				continue;
			}
			if (tx.sz == 0 && t2.mx < ty.mx)
			{
				puts("maybe");
				continue;
			}
		}
		if (tx.sz == 1 && ty.sz == 1)
			if (ty.mx <= tx.mx && t2.sz < (y - x - 1) && t2.mx < ty.mx)
			{
				puts("maybe");
				continue;
			}
		puts("false");
	}	
    return 0;
}
