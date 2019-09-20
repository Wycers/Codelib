#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 510;
const int M = N * N / 2;
const int K = 10; 
int x[N], y[N];
inline int sqr(int x)
{
    return x * x;
}
struct Edge
{
    int u, v, w;
    Edge () {}
    Edge (int a, int b)
    {
        u = a;
        v = b;
        w = sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
    } 
} e[M];
int cnt = 0;
inline bool cmp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}
int n, k;
vector<int> v[K];
int cost[K];

int fa[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", x + i, y + i);
    for (int i = 0; i < k; ++i)
    {
        v[i].clear();
        int num;
        scanf("%d%d", &num, cost + i);
        while (num--)
        {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }

    cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            e[++cnt] = Edge(i, j);
    sort(e + 1, e + cnt + 1, cmp);

    int ans = 0x7fffffff;
    for (int f = 0, t = (1 << k) - 1; f <= t; ++f)
    {
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        int res = 0, now = n - 1;
        for (int i = 0; i < k; ++i)
            if ((1 << i) & f)
            {
                res += cost[i];
                int fx = find(v[i][0]);
                for (int j : v[i])
                {
                    int fy = find(j);
                    if (fx == fy)
                        continue;
                    fa[fy] = fx;
                    --now;
                }
            }
        for (int i = 1; i <= cnt && now; ++i)
        {
            int fx = find(e[i].u);
            int fy = find(e[i].v);
            if (fx == fy)
                continue;
            fa[fx] = fy;
            res += e[i].w;
            --now;
        }
        ans = min(ans, res);
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