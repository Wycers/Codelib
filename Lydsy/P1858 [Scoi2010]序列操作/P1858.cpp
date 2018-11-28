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
int n, a[N];
//Struct
struct node
{
	int l, r, cnt[2], mx[2], sd[2][2], tag;
};
struct Tree
{
	node tr[8 * N];
	node Merge(node a, node b)
	{
		node t;
		t.l = a.l, t.r = b.r;
		For (i, 0, 1) t.cnt[i] = a.cnt[i] + b.cnt[i];
		For (i, 0, 1) t.mx[i] = max(a.mx[i], b.mx[i]);
		For (i, 0, 1)
			t.mx[i] = max(t.mx[i], a.sd[1][i] + b.sd[0][i]);
		For (i, 0, 1)
		{
			t.sd[0][i] = a.sd[0][i];
			if ((a.r - a.l + 1) == a.sd[0][i])
				t.sd[0][i] += b.sd[0][i];
			t.sd[1][i] = b.sd[1][i];
			if ((b.r - b.l + 1) == b.sd[1][i])
				t.sd[1][i] += a.sd[1][i];
		}
		t.tag = -1;
		return t;	
	}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	void Build(int k, int l, int r)
	{
		int mid = (l + r) >> 1, t;
		if (l == r)
		{
			t = a[l];
			tr[k].l = l; tr[k].r = r; tr[k].tag = -1;
			tr[k].cnt[0] = tr[k].mx[0] = tr[k].sd[0][0] = tr[k].sd[1][0] = (t == 0);
			tr[k].cnt[1] = tr[k].mx[1] = tr[k].sd[0][1] = tr[k].sd[1][1] = (t == 1);
			return;	
		}
		Build(ls, l, mid);
		Build(rs, mid + 1, r);
		tr[k] = Merge(tr[ls], tr[rs]);
	}
	void Tag(int k, int tag)
	{
		if (tr[k].tag == -1)
		{
			tr[k].tag = tag;
			return;	
		}
		if (tr[k].tag <= 1 && tag == 2)
			tr[k].tag ^= 1;
		else if (tag <= 1)
			tr[k].tag = tag; 
		else if (tr[k].tag == 2 && tag == 2)
			tr[k].tag = -1;
	}
	void Update(int k, int opt)
	{
		Tag(k, opt);
		if (opt == 2)
		{
			swap(tr[k].cnt[0], tr[k].cnt[1]);
			swap(tr[k].mx[0], tr[k].mx[1]);
			swap(tr[k].sd[0][0], tr[k].sd[0][1]);
			swap(tr[k].sd[1][0], tr[k].sd[1][1]);
			return;
		}
		int len = tr[k].r - tr[k].l + 1;
		tr[k].cnt[opt ^ 1] = 0; tr[k].cnt[opt] = len;
		tr[k].mx[opt ^ 1] = 0; tr[k].mx[opt] = len;
		tr[k].sd[0][opt ^ 1] = 0; tr[k].sd[0][opt] = len;
		tr[k].sd[1][opt ^ 1] = 0; tr[k].sd[1][opt] = len;
	} 
	void Pushdown(int k)
	{
		if (tr[k].tag == -1)
			return;
		if (ls <= 4 * n) Update(ls, tr[k].tag);
		if (rs <= 4 * n) Update(rs, tr[k].tag);
		tr[k].tag = -1;
	} 
	void Reverse(int k, int s, int t)
	{
		int l = tr[k].l, r = tr[k].r;
		Pushdown(k);
		if (l == s && r == t)
		{
			Update(k, 2);
			return;
		}
		int mid = (l + r) >> 1;
		if (t <= mid)
			Reverse(ls, s, t);
		else if (mid < s) 
			Reverse(rs, s, t);
		else Reverse(ls, s, mid), Reverse(rs, mid + 1, t);
		tr[k] = Merge(tr[ls], tr[rs]);
	}
	void Modify(int k, int s, int t, int val)
	{
		int l = tr[k].l, r = tr[k].r;
		Pushdown(k);
		if (l == s && r == t)
		{
			Update(k, val);
			return;
		}
		int mid = (l + r) >> 1;
		if (t <= mid) 
			Modify(ls, s, t, val);
		else if (mid < s)
			Modify(rs, s, t, val);
		else Modify(ls, s, mid, val), Modify(rs, mid + 1, t, val);
		tr[k] = Merge(tr[ls], tr[rs]);
	}
	node Query(int k, int s, int t)
	{
		int l = tr[k].l, r = tr[k].r;
		Pushdown(k);
		if (l == s && r == t)
			return tr[k];
		int mid = (l + r) >> 1;
		if (t <= mid)
			return Query(ls, s, t);
		if (mid < s)
			return Query(rs, s, t);
		return Merge(Query(ls, s, mid), Query(rs, mid + 1, t));
	}
} T;
//Code

int main()
{
	n = read(); int m = read(), x, y, opt;
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	T.Build(1, 1, n);
	while (m--)
	{
		opt = read(); x = read() + 1; y = read() + 1;
		if (opt <= 1)
			T.Modify(1, x, y, opt);
		else if (opt == 2)
			T.Reverse(1, x, y);
		else if (opt == 3)
			cout << T.Query(1, x, y).cnt[1] << endl;
		else if (opt == 4)
			cout << T.Query(1, x, y).mx[1] << endl;
	}
    return 0;
}

