#include <cstdio>
#include <queue>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 2 * 200 + 10;
const int M = 2 * 90000;
const int Inf = 0x3f3f3f3f;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

struct edge_ {
    int to, next, c;
} edge[M];
int head[N], cnt = 1;
void Insert(int u, int v, int c)
{
    edge[++cnt] = (edge_){v, head[u], c};
    head[u] = cnt;
}
void insert(int u, int v, int c)
{
    Insert(u, v, c);
    Insert(v, u, 0);
}
 
int n, m, S, T;
queue<int> q; 
int dis[N]; bool inq[N];
bool spfa()
{
    memset(dis, -1, sizeof(dis));
    memset(inq, false, sizeof(inq));
    q.push(S); dis[S] = 0; inq[S] = true; 
    while (!q.empty())
    {
        int now = q.front();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].c && dis[v] == -1)
            {
                dis[v] = dis[now] + 1;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
             }
        }
        q.pop(); inq[now] = false;
    }
    return dis[T] != -1;
}
int dfs(int u, int f)
{
    if (u == T)
        return f;
    int w, used = 0;
	for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (dis[v] == dis[u] + 1)
        {
            w = dfs(v, min(edge[i].c, f - used));
            edge[i].c -= w; edge[i ^ 1].c += w;
            used += w;
            if (used == f)
                return f;
        }
    }
    if (!used)
        dis[u] = -1;
    return used;
}

int ans = 0;
int dinic()
{
    while (spfa())
        ans += dfs(S, Inf);
	return ans;
}

void build()
{
    memset(head, 0, sizeof(head));
    cnt = 1;
    
    n = read(); m = read();
    S = 0; T = 2 * n + 1;
    for (int i = 1; i <= n; ++i)
    {
        insert(S, i, 1);
        insert(i + n, T, 1);
    }
    for (int i = 1, x, y; i <= m; ++i)
    {
        x = read(); y = read();
        insert(x, y + n, 1);
    }
}

bool vis[N];
void dfs(int now)
{
    vis[now] = true;
    printf("%d ", now);
    for (int i = head[now]; i; i = edge[i].next)
    {
        if (edge[i].to && vis[edge[i].to - n] == false && edge[i].c == 0)
            dfs(edge[i].to - n);
    }
}

void solve()
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        if (vis[i] == false)
        {
            dfs(i);
            puts("");
        }
}

int main()
{
    build();
    dinic();
    solve();
    printf("%d\n", n - ans);
    return 0;
}
