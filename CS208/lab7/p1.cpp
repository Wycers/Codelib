#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int n, d0, d;
struct point
{
    int p[3], mx[3], mn[3], l, r;
    point(int x = 0, int y = 0, int z = 0)
    {
        l = r = 0;
        p[0] = x, p[1] = y, p[2] = z;
    }
    int &operator[](int x) { return p[x]; }
    // 以 d0 维为第一关键
    bool operator < (point b) const
    {
        for (int i = 0; i < d; ++i)
        {
            int dt = (d0 + i) % d;
            if (p[dt] != b[dt])
                return p[dt] < b[dt];
        }
        return true;
    }
    void print()
    {
        for (int i = 0; i < d; ++i)
            printf("%d%c", p[i], i == d - 1 ? '\n' : ' ');
    }
};
unsigned long long ans = 0xffffffffffffffff;
int cnt = 0;
pair<point, point> ans_pair;

unsigned long long sqr(int x)
{
    return 1ll * x * x;
}
struct kdtree
{
    point t[N], now;
    void update(int k)
    {
        int l = t[k].l, r = t[k].r;
        for (int i = 0; i < d; i++)
        {
            int *mn = &t[k].mn[i], *mx = &t[k].mx[i];
            if (l)
            {
                *mn = min(*mn, t[l].mn[i]);
                *mx = max(*mx, t[l].mx[i]);
            }
            if (r)
            {
                *mn = min(*mn, t[r].mn[i]);
                *mx = max(*mx, t[r].mx[i]);
            }
        }
    }
    void build(int &k, int l, int r, int x)
    {
        d0 = x;
        int mid = (l + r) >> 1;
        k = mid;
        nth_element(t + l, t + k, t + r + 1);
        for (int i = 0; i < d; i++)
            t[k].mn[i] = t[k].mx[i] = t[k][i];
        if (l < k) build(t[k].l, l, mid - 1, (x + 1) % d);
        if (k < r) build(t[k].r, mid + 1, r, (x + 1) % d);
        update(k);
    }
    // 计算点距离
    unsigned long long getdis(int k)
    {
        unsigned long long res = 0;
        for (int i = 0; i < d; ++i)
            res += sqr(t[k][i] - now[i]);
        return res;
    }
    // 计算区域距离
    unsigned long long calc(int k)
    {
        if (!k)
            return 0xffffffffffffffff;
        unsigned long long res = 0;
        for (int i = 0; i < d; ++i)
            if (now[i] < t[k].mn[i])
                res += sqr(t[k].mn[i] - now[i]);
            else if (now[i] > t[k].mx[i])
                res += sqr(t[k].mx[i] - now[i]);
        return res;
    }
    void query(int k)
    {
        if (!k) return;
        unsigned long long d1 = calc(t[k].l);
        unsigned long long d2 = calc(t[k].r);
        unsigned long long d0 = getdis(k);
        
        if (d0 < ans && d0 != 0)
        {
            ans = d0;
            ans_pair = make_pair(t[k], now);
        }
        if (d0 == 0)
        {
            if (++cnt > 1)
            {
                ans = 0;
                ans_pair = make_pair(t[k], now);
            }
        }
        
        if (d1 < d2)
        {
            if (d1 < ans) query(t[k].l);
            if (d2 < ans) query(t[k].r);
        }
        else
        {
            if (d2 < ans) query(t[k].r);
            if (d1 < ans) query(t[k].l);
        }
    }
} tr;
int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < d; ++j)
            scanf("%d", &tr.t[i][j]);
    if (d == 1)
    {
        d0 = 0;
        sort(tr.t + 1, tr.t + n + 1);
        int mn = 0x7fffffff, tag = 2;
        for (int i = 2; i <= n; ++i)
            if (tr.t[i][0] - tr.t[i - 1][0] < mn)
            {
                mn = tr.t[i][0] - tr.t[i - 1][0];
                tag = i;
            }
        tr.t[tag - 1].print();
        tr.t[tag].print();
    }
    else
    {
        int rt; tr.build(rt, 1, n, 0);
        for (int i = 1; i <= n; ++i)
        {
            cnt = 0;
            tr.now = tr.t[i];
            tr.query(rt);
        }
        d0 = 0;
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
    }
    return 0;
}