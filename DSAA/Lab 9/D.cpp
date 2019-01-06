#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e3 + 10;
const int M = 2e4 + 10;
int n, m;
int fa[N], u[M], v[M], w[M], tag[M];
int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
inline bool cmp(const int a, const int b) {
    return w[a] < w[b];
}
int k;
void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    m += k;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", u + i, v + i,  w + i);
        tag[i] = i;
    }
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    sort(tag + 1, tag + m + 1, cmp);
    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        int x = u[tag[i]], y = v[tag[i]];
        int fx = getfa(x), fy = getfa(y);
        if (fx == fy)
            continue;
        ans += w[tag[i]];
        fa[fx] = fy;
        if (++cnt == n - 1)
            break;
    }
    if (cnt == n - 1)
        printf("%d\n", ans);
    else
        puts("-1");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}