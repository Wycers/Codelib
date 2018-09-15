#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 3e4 + 10;
const int Inf = 0x3f3f3f3f;
const unsigned long long Ha = 0xFFFFFFFFFFFFFFFF;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

struct Edge
{
    int to, next;
} edge[2 * N];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
} 
int n, fa[N], siz[N], dep[N], son[N];
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
        if (!son[u] || siz[son[u]] < siz[v])
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
    unsigned long long sum, lazy_add, lazy_mul = 1;
    bool lazy_sub;
} tr[4 * N];
inline void pd(int k, int l, int r)
{
    if (tr[k].lazy_add)
    {
        tr[k << 1].lazy_add += tr[k].lazy_add;
        tr[k << 1 | 1].lazy_add += tr[k].lazy_add;
        tr[k].lazy_add = 0;
    }
    if (tr[k].lazy_mul > 1)
    {
        tr[k << 1].lazy_mul *= tr[k].lazy_mul;
        tr[k << 1 | 1].lazy_mul *= tr[k].lazy_mul;
        tr[k].lazy_mul = 1;
    }
    if (tr[k].lazy_sub) 
    {
        tr[k << 1].lazy_sub ^= 1;
        tr[k << 1 | 1].lazy_sub ^= 1;
        tr[k].lazy_sub = 0;
    }
}
int QuerySum(int k, int l, int r, int L, int R)
{
    pd(k, l, r);
    if (l == L && r == R)
        return tr[k].sum;
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid)
        res += QuerySum(k << 1, l, mid, L, min(mid, R));
    if (mid < R)
        res += QuerySum(k << 1 | 1, mid + 1, r, max(L, mid + 1), R);
    return res;
}
 
unsigned long long SolveSum(int x, int y)
{
    unsigned long long sum = 0;
    while (belong[x] != belong[y])
    {
        if (dep[belong[x]] < dep[belong[y]])
            swap(x, y);
        sum += QuerySum(1, 1, n, pos[belong[x]], pos[x]);
        x = fa[belong[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    sum += QuerySum(1, 1, n, pos[x], pos[y]);
    return sum;
}
void Add(int k, int l, int r, int L, int R, unsigned long long x)
{
    pd(k, l, r);
    if (l == L && r == R)
    {
        tr[k].lazy_add += x;
        tr[k].sum += (r - l + 1) * x;
        return;
    }
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid)
        Add(k << 1, l, mid, L, min(mid, R), x);
    if (mid < R)
        Add(k << 1 | 1, mid + 1, r, max(L, mid + 1), R, x);
    tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
}
void SolveAdd(int x, int y, int z) {
    while (belong[x] != belong[y]) {
        if (dep[belong[x]] < dep[belong[y]]) 
            swap(x, y);
        Add(1, 1, n, pos[belong[x]],pos[x], z);
        x = fa[belong[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    Add(1, 1, n, pos[x], pos[y], z);
}

void mul(int k, int l, int r, int x, unsigned long long y)
{
    if (l == r)
    {
        tr[k].sum *= y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        mul(k << 1, l, mid, x, y);
    else
        mul(k << 1 | 1, mid + 1, r, x, y);
    tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
}
void Mul(int k, int l, int r, int L, int R, int x)
{
    pd(k, l, r);
    for (int i = L; i <= R; ++i)
        mul(1, 1, n, i, x);
    // if (l == L && r == R)
    // {
    //     tr[k].lazy_mul *= x;
    //     tr[k].sum *= tr[k].lazy_mul;
    //     return;
    // }
    // int mid = (l + r) >> 1;
    // int res = 0;
    // if (L <= mid)
    //     Mul(k << 1, l, mid, L, min(mid, R), x);
    // if (mid < R)
    //     Mul(k << 1 | 1, mid + 1, r, max(L, mid + 1), R, x);
    // tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
}
void SolveMul(int x, int y, int z) {
    while (belong[x] != belong[y]) {
        if (dep[belong[x]] < dep[belong[y]]) 
            swap(x, y);
        Mul(1, 1, n, pos[belong[x]],pos[x], z);
        x = fa[belong[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    Mul(1, 1, n, pos[x], pos[y], z);
}

void sub(int k, int l, int r, int x)
{
    if (l == r)
    {
        tr[k].sum = Ha - tr[k].sum;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        sub(k << 1, l, mid, x);
    else
        sub(k << 1 | 1, mid + 1, r, x);
    tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
}
void Sub(int k, int l, int r, int L, int R)
{
    pd(k, l, r);
    for (int i = L; i <= R; ++i)
        sub(1, 1, n, i);
    // if (l == L && r == R)
    // {
    //     tr[k].lazy_sub ^= 1;
    //     tr[k].sum = Ha - tr[k].sum;
    //     return;
    // }
    // int mid = (l + r) >> 1;
    // int res = 0;
    // if (L <= mid)
    //     Sub(k << 1, l, mid, L, min(mid, R));
    // if (mid < R)
    //     Sub(k << 1 | 1, mid + 1, r, max(L, mid + 1), R);
    // tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
}
void SolveSub(int x, int y) {
    while (belong[x] != belong[y]) {
        if (dep[belong[x]] < dep[belong[y]]) 
            swap(x, y);
        Sub(1, 1, n, pos[belong[x]],pos[x]);
        x = fa[belong[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    Sub(1, 1, n, pos[x], pos[y]);
}

void solve()
{
    memset(head, 0, sizeof head); 
    memset(fa, 0, sizeof fa);
    memset(siz, 0, sizeof siz);
    memset(dep, 0, sizeof dep);
    memset(son, 0, sizeof son);
    memset(pos, 0, sizeof pos);
    memset(belong, 0, sizeof belong);
    memset(tr, 0, sizeof tr);
    cnt = 0; sz = 0;

    for (int i = 2, f; i <= n; ++i)
    {
        f = read();
        insert(i, f);
        insert(f, i);
    }
    

    dfs1(1);
    dfs2(1, 1);
      
    int opt, u, v, x, q = read();
    while (q--)
    {
        opt = read(); u = read(); v = read();
        if (opt == 1 || opt == 2)
            x = read();
        if (opt == 1)
            SolveMul(u, v, x);
        else if (opt == 2)
            SolveAdd(u, v, x);
        else if (opt == 3)
            SolveSub(u, v);
        else 
            printf("%llu\n", SolveSum(u, v));
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    while (~scanf("%d", &n))
        solve();
    return 0;
}