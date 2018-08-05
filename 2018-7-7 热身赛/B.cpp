#pragma comment(linker, "/STACK:100000000,100000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5e4 + 10;
const int Inf = 0x3f3f3f3f;
struct Edge
{
    int to, next;
} edge[N << 1];
int head[N], cnt = 0;


void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
int n, m, a[N], fa[N], siz[N], dep[N], son[N];
void dfs1(int u)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
        if (!son[u] || siz[v] > siz[son[u]])
            son[u] = v;
    }
}

int sz, pos[N], belong[N];
void dfs2(int u, int chain)
{
    pos[u] = ++sz;
    belong[u] = chain;
    if (!son[u])
        return;
    dfs2(son[u], chain);
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

struct node
{
    int val;
} tr[4 * N];

void pushdown(int k)
{
    if (tr[k].val == 0)
        return;
    tr[k << 1].val += tr[k].val;
    tr[k << 1 | 1].val += tr[k].val;
    tr[k].val = 0;
}
void build(int k, int l, int r)
{
    tr[k].val = 0;
    if (l == r)
    {
        tr[k].val = a[pos[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}
void modify(int k, int l, int r, int L, int R, int x)
{
    if (L == l && R == r)
    {
        tr[k].val += x;
        return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if (L <= mid)
        modify(k << 1, l, mid, L, min(mid, R), x);
    if (mid < R)
        modify(k << 1 | 1, mid + 1, r, max(L, mid + 1), R, x);
}
int query(int k, int l, int r, int x)
{
    if (l == r)
        return tr[k].val;
    
    pushdown(k);
    int mid = (l + r) >> 1;
    if (x <= mid)
        return query(k << 1, l, mid, x);
    else
        return query(k << 1 | 1, mid + 1, r, x);
}

void solve(int x, int y, int val)
{
    while (belong[x] != belong[y])
    {
        if (dep[belong[x]] < dep[belong[y]])
            swap(x, y);
        modify(1, 1, n, pos[belong[x]], pos[x], val);
    }
    if (dep[x] > dep[y])
        swap(x, y);
    modify(1, 1, n, pos[x], pos[y], val);
}

int main()
{
    int m, q, x, y, val; char str[5];
    while (scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        memset(head, 0, sizeof head);
        memset(son, 0, sizeof son);
        cnt = 0; sz = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &x, &y);
            insert(x, y);
            insert(y, x);
        }
        dfs1(1);
        dfs2(1, 1);
        
        build(1, 1, n);

        while (q--)
        {
            scanf("%s", str);
            if (str[0] == 'Q')
            {
                scanf("%d", &x);
                printf("%d\n", query(1, 1, n, pos[x]));
            }
            else
            {
                scanf("%d%d%d", &x, &y, &val);
                if (str[0] == 'D')
                    val = -val;
                solve(x, y, val);
            }
        }
    }
    return 0;
}