#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e5 + 10;
struct Edge
{
    int to, next;
} edge[M];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
int n, m;
bool vis[N];
queue<int> q, tmp;
void solve()
{
    memset(head, 0, sizeof head);
    cnt = 0;

    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        insert(x, y);
    }
    scanf("%d", &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        q = tmp;

        q.push(x);
        memset(vis, false, sizeof vis);
        bool flag = false;
        while (!q.empty())
        {
            int now = q.front(); q.pop();
            for (int i = head[now]; i; i = edge[i].next)
            {
                int v = edge[i].to;
                if (v == y)
                {
                    flag = true;
                    break;
                }
                if (vis[v])
                    continue;
                vis[v] = true;
                q.push(v);
            }
            if (flag)
                break;
        }
        puts(flag ? "YES" : "NO");
    }
    
}
int main()
{
    while (!tmp.empty())
        tmp.pop();
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}