#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
const int M = 1e4 + 10;
int n, m;
int fa[N], u[M], v[M], w[M], tag[M];
int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
inline bool cmp(const int a, const int b) {
    return w[a] < w[b];
}
int res;
bool judge(int x)
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    res = 0;
    int tmp = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (w[tag[i]] < x)
            continue;
        int x = u[tag[i]], y = v[tag[i]];
        int fx = getfa(x), fy = getfa(y);
        if (fx == fy)
            continue;
        res += w[tag[i]];
        if (++tmp == n - 1)
            return true;
        fa[fx] = fy;
    }
    return false;
}
void solve()
{
    scanf("%d%d", &n, &m);
    int l = 0x3f3f3f3f, r = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", u + i, v + i,  w + i);
        l = min(l, w[i]);
        r = max(r, w[i]);
        tag[i] = i;
    }
    sort(tag + 1, tag + m + 1, cmp);
    judge(l);
    int ans = res;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (judge(mid))
        {
            ans = res;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}