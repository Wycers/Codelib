#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 6e3 + 10;
const int M = 2e5 + 10;
const double eps = 1e-8;
struct Edge
{
    int to, next,  w;
} edge[M];
int head[N], cnt = 0;
void insert(int u, int v, int w)
{
    edge[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}
int n, m, k;

priority_queue<pair<int, int> > q;
int S[2], dis[2][N]; bool inq[N];
void dij(int f, int s) 
{
    memset(inq, false, sizeof inq);
    for (int i = 1; i <= n; ++i)
        dis[f][i] = 0x3f3f3f3f;
    q.emplace(dis[f][s] = 0, s);
    while (!q.empty())
    {
        int u = q.top().second; q.pop();
        if (inq[u])
            continue;
        inq[u] = true;
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if (dis[f][v] > dis[f][u] + edge[i].w) {
                dis[f][v] = dis[f][u] + edge[i].w;
                q.emplace(-dis[f][v], v);
            }
        }
    }
}
int ans = 0x3f3f3f3f;
void solve()
{
    // 清空前向星
    memset(head, 0, sizeof head);
    cnt = 0;

    // 读入
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        insert(u, v, w);
        insert(v, u, w);
    }

    // 处理需要经过的点
    k = 0;
    scanf("%d", &S[k++]);
    scanf("%d", &S[k++]);
    for (int i = 0; i < k; ++i)
        dij(i, S[i]);
    
    ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, max(dis[0][i], dis[1][i]));
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}