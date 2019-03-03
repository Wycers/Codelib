#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 110;
const int M = 2e4 + 10;
const double eps = 1e-8;
struct Edge
{
    int to, next; double w;
} edge[M];
int head[N], cnt = 0;
void insert(int u, int v, double w)
{
    edge[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}
struct point
{
    double x, y, z;
    void init()
    {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    double dis(const point &q) const
    {
        double dx = q.x - x;
        double dy = q.y - y;
        double dz = q.z - z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
} s, t;
struct ball
{
    point p; double r;
    void init()
    {
        p.init();
        scanf("%lf", &r);
    }
} p[N];
int n;
 
priority_queue<pair<int, int> > q;
double dis[N]; bool inq[N];
double dij(int s) 
{
    memset(inq, false, sizeof inq);
    for (int i = 1; i <= n + 1; ++i)
        dis[i] = 1e9;
    q.emplace(dis[s] = 0, s);
    while (!q.empty())
    {
        int u = q.top().second; q.pop();
        if (inq[u])
            continue;
        inq[u] = true;
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                q.emplace(-dis[v], v);
            }
        }
    }
    return dis[n + 1];
}
void solve()
{
    memset(head, 0, sizeof head);
    cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        p[i].init();
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            double d = p[i].p.dis(p[j].p) - p[i].r - p[j].r;
            if (d < 0)
                d = 0;
            insert(i, j, d);
            insert(j, i, d);
        }
    s.init();
    for (int i = 1; i <= n; ++i)
    {
        double d = p[i].p.dis(s) - p[i].r;
        if (d < 0)
            d = 0;
        insert(0, i, d);
    }
    t.init();
    for (int i = 1; i <= n; ++i)
    {
        double d = p[i].p.dis(t);
        if (d < p[i].r)
            insert(i, n + 1, 0);
        else
            insert(i, n + 1, (d - p[i].r));
    }
    insert(0, n + 1, s.dis(t));
    printf("%d\n", (int)round(100.0 * dij(0)));
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}