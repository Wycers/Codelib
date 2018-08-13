#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int Inf = 0x3f3f3f3f;
struct Edge
{
    int to, next, c;
} edge[M];
int head[N], cnt = 0;
void insert(int u, int v, int c)
{
    edge[++cnt] = (Edge){v, head[u], c};
    head[u] = cnt;
}

int n, m;
void readin()
{
    int u, v, c;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &c);
        insert(u, v, c);
        insert(v, u, c);
    }
}

struct Data
{
    int u, c, res, from;
};

bool operator < (const Data &a, const Data &b)
{
    return a.res > b.res;
}
priority_queue<Data> q;
int ans; bool vis[N];
void bfs()
{
    while (!q.empty())
        q.pop();
    q.push((Data){1, 0, 0, 0});
    while (!q.empty())
    {
        Data now = q.top(); q.pop();
        if (now.u == n)
        {
            ans = now.res;
            return;
        }
        if (vis[now.u])
        {
            bool flag = false;
            for (int i = head[now.u]; i; i = edge[i].next)
            {
                int v = edge[i].to;
                if (v == now.from && edge[i].c == now.c)
                    continue;
                if (edge[i].c == now.c)
                    q.push((Data){v, edge[i].c, now.res, now.u});
            }   
        }
        else
        {
            for (int i = head[now.u]; i; i = edge[i].next)
            {
                int v = edge[i].to;
                if (v == now.from && edge[i].c == now.c)
                    continue;
                q.push((Data){v, edge[i].c, now.res + (edge[i].c != now.c), now.u});
            }
        }
        vis[now.u] = true;
    }
}
void solve()
{
    bfs();
    printf("%d\n", ans);
}

int main()
{
    freopen("test.in", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(head, 0, sizeof head); cnt = 0;
        memset(vis, false, sizeof vis);
        ans = -1;
        readin();
        solve();
    }
    return 0;
}