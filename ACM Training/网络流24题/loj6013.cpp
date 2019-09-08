#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int Inf = 0x3f3f3f3f;
const int N = 3e2 + 10;
const int M = 2e4 + 10;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}
int ans;
struct Edge {
    int to, next, c, w;
} edge[2 * M];
int head[N], cnt;
void Insert(int u, int v, int c, int w)
{
    edge[++cnt] = (Edge){v, head[u], c, w};
    head[u] = cnt;
}
void insert(int u, int v, int c, int w)
{
    Insert(u, v, c,  w);
    Insert(v, u, 0, -w);
}

int S, T;
queue<int> q;
bool inq[N]; int dis[N];
bool spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(inq, 0, sizeof(inq));
    q.push(T); inq[T] = true; dis[T] = 0;
    while (!q.empty())
    {
        int now = q.front();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if(dis[now] - edge[i].w < dis[v] && edge[i ^ 1].c)
            {
                dis[v] = dis[now] - edge[i].w;
                if(!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
        q.pop(); inq[now] = false;
    }
    return dis[S] != Inf;
}

bool vis[N];
int dfs(int x, int f)
{
    vis[x] = true;
    if (x == T)
        return f;
    int c, used = 0;
    
    for (int i = head[x]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (edge[i].c && !vis[v] && dis[x] - edge[i].w == dis[v])
        {
            c = dfs(v, min(edge[i].c, f - used));
            edge[i].c -= c; edge[i ^ 1].c += c;
            ans += edge[i].w * c;
            used += c;
            if (used == f)
                return f;
        }
    }
    return used;
}
int zkw()
{
    int f = 0;
    while(spfa())
    {
        vis[T] = 1;
        while(vis[T])
        {
            memset(vis, 0, sizeof(vis));
            f += dfs(0, 0x3f3f3f3f);
        }
    }
    return f;
}



int n, a[N];
void build() 
{
    memset(head, 0, sizeof(head));
    cnt = 1; ans = 0; S = 0; T = 2 * n + 1;
    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i];
    s /= n;
    for (int i = 1; i <= n; ++i)
        a[i] -= s;
    for (int i = 1; i <= n; ++i)
        if (a[i] > 0)
            insert(S, i, a[i], 0);
        else 
            insert(i + n, T, -a[i], 0);
    for (int i = 2; i <= n; ++i)
    {
        insert(i, i - 1, Inf, 1);
        insert(i, n + i - 1, Inf, 1);
    }
    for (int i = 1; i < n; ++i)
    {
        insert(i, i + 1, Inf, 1);
        insert(i, n + i + 1, Inf, 1);
    }
    insert(n, 1, Inf, 1);
    insert(1, n, Inf, 1);
    insert(n, n + 1, Inf, 1);
    insert(1, n + n, Inf, 1);
}
int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    build(); 
    zkw();
    printf("%d\n", ans);
    return 0;
}