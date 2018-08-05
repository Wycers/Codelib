//=============================================================
// File Name: 1003.cpp
// Author: Wycer
// Created Time: 2018-05-19 12:45
//=============================================================
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') 
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}


struct node
{
	int l, r, cnt;
	node ()
	{
		l = r = cnt = 0;
	}
} tr[50 * N];
int n, q, a[N], root[N], cnt = 0;
	

inline void insert(int &k, int l, int r, int x)
{
	tr[++cnt] = tr[k];
	k = cnt;
	++tr[k].cnt;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	if (x <= mid)
		insert(tr[k].l, l, mid, x);
	else
		insert(tr[k].r, mid + 1, r, x);
}
inline int query(int x, int y, int l, int r, int k)
{
	if (l == r)
		return l;
	int tmp = tr[tr[y].l].cnt - tr[tr[x].l].cnt; 
	int mid = (l + r) >> 1;
	if (k <= tmp)
		return query(tr[x].l, tr[y].l, l, mid, k);
	else
		return query(tr[x].r, tr[y].r, mid + 1, r, k - tmp);
}

void readin()
{
	cnt = 0; memset(root, 0, sizeof(root));
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	for (int i = 1; i <= n; ++i)
	{
		root[i] = root[i - 1];
		insert(root[i], 1, n, a[i]);
	}
}
void solve()
{
	int x, y, l, r, mid, ans;
	while (q--)
	{
		x = read(); y = read();
		ans = l = 1; r = y - x + 1; 
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (query(root[x - 1], root[y], 1, n, y - x + 2 - mid) >= mid)
			{
				ans = mid;
				l = mid + 1;
			}
			else 
				r = mid - 1;
		}
		printf("%d\n", ans);
	}
}

int main()
{
	while (scanf("%d%d", &n, &q))
	{
		readin();
		solve();
	}
	return 0;
}
