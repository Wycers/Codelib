//=============================================================
// File Name: poj-2104.cpp
// Author: Wycer
// Created Time: 2018-05-07 17:33
//=============================================================
#include <cstdio>
#include <algorithm>
const int N = 1e5 + 10;
using namespace std;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int n, m, a[N], tag[N], back[N], root[N];
void readin()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        tag[i] = i;
        back[i] = a[i];
    }
}

struct node
{
    int l, r, cnt;
    node()
    {
        l = r = cnt = 0;
    }
} tr[20 * N];
int cnt = 0;
void insert(int &k, int l, int r, int x)
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
int query(int x, int y, int l, int r, int k)
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
bool cmp(int x, int y)
{
    return a[x] < a[y];
}
int r[N];
void solve()
{
    sort(tag + 1, tag + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        r[tag[i]] = i;
    for (int i = 1; i <= n; ++i)
    {
        root[i] = root[i - 1];
        insert(root[i], 1, n, r[i]);
    }

    int x, y, k;
    while (m--)
    {
        x = read();
        y = read();
        k = read();
        printf("%d\n", a[tag[query(root[x - 1], root[y], 1, n, k)]]);
    }
}

int main()
{
    readin();
    solve();
    return 0;
}
