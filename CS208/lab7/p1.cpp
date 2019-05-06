#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, d0, d;
struct point
{
    int p[3], mx[3], mn[3], w, val, l, r;
    point(int x = 0, int y = 0, int z = 0)
    {
        l = 0, r = 0;
        p[0] = x, p[1] = y, p[2] = z;
    }
    int &operator[](int x) { return p[x]; }
    // 以 d0 维为第一关键
    bool operator<(point &b) const
    {
        if (p[d0] == b[d0])
        {
            const int d1 = (d0 + 1) % 3;
            if (p[d1] == b[d1])
            {
                const int d2 = (d1 + 2) % 3;
                return p[d2] < b[d2];
            }
            else
                return p[d1] < b[d1];
        }
        else
            return p[d0] < b[d0];
    }
    void print()
    {
        for (int i = 0; i < d; ++i)
            printf("%d%c", p[i], i == d - 1 ? '\n' : ' ');
    }
} a[N];
struct kdtree
{
    point t[N];
    void update(int k)
    {
        int l = t[k].l, r = t[k].r;
        for (int i = 0; i < d; i++)
        {
            int mn = 0x3f3f3f3f, mx = -0x3f3f3f3f;
            if (l)
            {
                mn = min(mn, t[l].mn[i]);
                mx = max(mx, t[l].mx[i]);
            }
            if (r)
            {
                mn = min(mn, t[r].mn[i]);
                mx = max(mx, t[r].mx[i]);
            }
        }
    }
    void build(int &x, int l, int r, int now)
    {
        d0 = now;
        int mid = (l + r) >> 1;
        nth_element(a + l, a + mid, a + r);
        t[mid] = a[mid];
        x = mid;
        for (int i = 0; i < d; i++)
            t[mid].mn[i] = t[mid].mx[i] = t[mid][i];
        if (l < mid) build(t[mid].l, l, mid - 1, (now + 1) % d);
        if (r > mid) build(t[mid].r, mid + 1, r, (now + 1) % d);
        update(mid);
    }
};
int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            scanf("%d", &a[i][j]);
    if (d == 1)
    {
        d0 = 0;
        sort(a, a + n);
        int mn = 0x7fffffff, tag = 1;
        for (int i = 1; i < n; ++i)
            if (a[i][0] - a[i - 1][0] < mn)
            {
                mn = a[i][0] - a[i - 1][0];
                tag = i;
            }
        a[tag - 1].print();
        a[tag].print();
    }
    else
    {
    }
    return 0;
}