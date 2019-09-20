#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int inf = 0x3f3f3f3f;
struct Edge{
    int to;
    Edge *next;
} edge[M], *head[N], *now;
void insert(int u, int v)
{
    now->to = v;
    now->next = head[u];
    head[u] = now++;
}
int n, m, s;
priority_queue<pair<int, int> > q;
int dis[N]; bool vis[N];
void dij (int s) 
{
    memset(dis, 0x3f, sizeof dis);
    memset(vis, false, sizeof vis);
    q.emplace(dis[s] = 0, s);
    while (!q.empty())
    {
        int u = q.top().second; q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (Edge *t = head[u]; t; t = t->next) {
            int v = t->to;
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.emplace(-dis[v], v);
            }
        }
    }
}
void solve()
{
    now = edge;
    memset(head, NULL, sizeof head);
    scanf("%d%d%d", &n, &m, &s);
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        insert(u, v);
        insert(v, u);
    }
    dij(s);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", dis[i] == inf ? -1 : dis[i], i == n ? '\n' : ' ');
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}