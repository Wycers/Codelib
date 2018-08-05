//=============================================================
// File Name: loj-2016.cpp
// Author: Wycer
// Created Time: 2018-05-09 22:59
//=============================================================
#include <cstdio>
#include <algorithm>
const int N = 2e5 + 10;
using namespace std;
int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

int n, m, a[N];
void readin()
{
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
}


struct node
{
	int l, r, cnt;
	node ()
	{
		l = r = cnt = 0;
	}
} tr[40 * N];
int root[N], cnt = 0;
void insert(int &k, int L, int R, int x)
{
	tr[++cnt] = tr[k];
	k = cnt;
	tr[k].cnt += 1;
	if (L == R)
		return;
	int mid = (L + R) >> 1;
	if (x <= mid)
		insert(tr[k].l, L, mid, x);
	else
		insert(tr[k].r, mid + 1, R, x);
}
int query(int x, int y, int L, int R, int l, int r)
{
	if (l > r)
		return 0;
	if (l <= L && R <= r)
		return tr[y].cnt - tr[x].cnt;
	int mid = (L + R) >> 1;
	if (r <= mid)
		return query(tr[x].l, tr[y].l, L, mid, l, r);
	else if (l > mid)
		return query(tr[x].r, tr[y].r, mid + 1, R, l, r);
	else 
		return query(tr[x].l, tr[y].l, L, mid, l, mid) + query(tr[x].r, tr[y].r, mid + 1, R, mid + 1, r);
}
void solve()
{
	for (int i = 1; i <= n; ++i)
	{
		root[i] = root[i - 1];
		insert(root[i], 1, 100000, a[i]);
	}
	int b, x, l, r;
	while (m--)
	{
		b = read(); x = read(); l = read(); r = read();
		int res = 0;
		for (int i = 17; i >= 0; --i)
		{
			int L, R, t;
			if (b & (1 << i))
			{
				L = res;
				R = res + (1 << i) - 1;
				t = 0;
			}
			else
			{
				L = res + (1 << i);
				R = res + (1 << (i + 1)) - 1;
				t = 1;
			}
			if (!query(root[r], root[l - 1], 1, 100000, max(0, L - x), min(R - x, 100000)))
				t ^= 1;
			res |= t << i;
		}
		printf("%d\n", res ^ b);
	}
}
int main()
{
	readin();
	solve();
	return 0;
}
