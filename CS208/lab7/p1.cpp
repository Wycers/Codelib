#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int n, d, D;
struct node
{
    int p[3], mx[3], mn[3], l, r;
    node(int x = 0, int y = 0, int z = 0)
    {
        l = r = 0;
        p[0] = x, p[1] = y, p[2] = z;
    }
    int &operator[](int x) { return p[x]; }
    // 以 D 维为第一关键字
    bool operator < (node b) const
    {
        return p[D] < b[D];
    }
    void print()
    {
        for (int i = 0; i < d; ++i)
            printf("%d%c", p[i], i == d - 1 ? '\n' : ' ');
    }
};
unsigned long long ans = 0xffffffffffffffff;
int cnt = 0;
pair<node, node> ans_pair;
node tr[N], now;
void update(int k)
{
    int l = tr[k].l, r = tr[k].r;
    for (int i = 0; i < d; i++)
    {
        if (l)
        {
            tr[k].mn[i] = min(tr[k].mn[i], tr[l].mn[i]);
            tr[k].mx[i] = max(tr[k].mx[i], tr[l].mx[i]);
        }
        if (r)
        {
            tr[k].mn[i] = min(tr[k].mn[i], tr[r].mn[i]);
            tr[k].mx[i] = max(tr[k].mx[i], tr[r].mx[i]);
        }
    }
}
void build(int &k, int l, int r, int x)
{
    D = x;
    int mid = (l + r) >> 1;
    k = mid;
    nth_element(tr + l, tr + k, tr + r + 1);
    for (int i = 0; i < d; i++)
        tr[k].mn[i] = tr[k].mx[i] = tr[k][i];
    if (l < k) build(tr[k].l, l, mid - 1, (x + 1) % d);
    if (k < r) build(tr[k].r, mid + 1, r, (x + 1) % d);
    update(k);
}
unsigned long long sqr(int x)
{
    return 1ll * x * x;
}
// 计算点距离
unsigned long long getdis(int k)
{
    unsigned long long res = 0;
    for (int i = 0; i < d; ++i)
        res += sqr(tr[k][i] - now[i]);
    return res;
}
// 计算区域距离
unsigned long long calc(int k)
{
    if (!k)
        return 0xffffffffffffffff;
    unsigned long long res = 0;
    for (int i = 0; i < d; ++i)
        if (now[i] < tr[k].mn[i])
            res += sqr(tr[k].mn[i] - now[i]);
        else if (now[i] > tr[k].mx[i])
            res += sqr(tr[k].mx[i] - now[i]);
    return res;
}

void query(int k)
{
    if (!k) return;
    unsigned long long d1 = calc(tr[k].l);
    unsigned long long d2 = calc(tr[k].r);
    unsigned long long d0 = getdis(k);

    if (d0 == 0)
    {
        if (++cnt > 1)
        {
            ans = 0;
            ans_pair = make_pair(tr[k], now);
        }
    }
    else
    {
        if (d0 < ans)
        {
            ans = d0;
            ans_pair = make_pair(tr[k], now);
        }
    }
    if (d1 < d2)
    {
        if (d1 < ans) query(tr[k].l);
        if (d2 < ans) query(tr[k].r);
    }
    else
    {
        if (d2 < ans) query(tr[k].r);
        if (d1 < ans) query(tr[k].l);
    }
}
int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < d; ++j)
            scanf("%d", &tr[i][j]);
    int rt; build(rt, 1, n, 0);
    for (int i = 1; i <= n; ++i)
    {
        cnt = 0;
        now = tr[i];
        query(rt);
    }
    D = 0;
    if (ans_pair.first < ans_pair.second)
    {
        ans_pair.first.print();
        ans_pair.second.print();
    }
    else
    {
        ans_pair.second.print();
        ans_pair.first.print();
    }
    return 0;
}