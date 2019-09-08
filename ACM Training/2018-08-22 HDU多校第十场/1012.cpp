#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int Inf = 0x3f3f3f3f;
const int N = 4e2 + 10;
const int M = 1e5 + 10;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}
int ans;
struct Edge {
    int to, next, c, w;
} edge[M];
int head[N], cnt;
void Insert(int u, int v, int c, int w)
{
    edge[++cnt] = (Edge){v, head[u], c, w};
    head[u] = cnt;
}
void insert(int u, int v, int c, int w)
{
    // printf("%d %d %d %d\n", u, v, c, w);
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
            f += dfs(S, Inf);
        }
    }
    return f;
}
 
int n, m, k, w, a[N], s[N], t[N], v[N], op[N];
void build()
{
    memset(head, 0, sizeof(head));
    cnt = 1; ans = 0; S = 0; T = 2 * m + 2;

    int tmp = T - 1;
    insert(S, tmp, k, 0);
    for (int i = 1; i <= m; ++i)
        insert(tmp, i, 1, 0);
    for (int i = 1; i <= m; ++i)
        insert(i, i + m, 1, -v[i]);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
            if (t[i] <= s[j])
                insert(i + m, j, 1, (op[i] == op[j]) * w);
    for (int i = 1; i <= m; ++i)
        insert(i + m, T, 1, 0);
}

int main()
{
    freopen("test.in", "r", stdin);
    for (int T = read(); T; --T)
    {
        n = read(); m = read(); k = read(); w = read();
        for (int i = 1; i <= m; ++i)
        {
            s[i] = read();
            t[i] = read();
            v[i] = read();
            op[i] = read();
        }
        build();
        zkw();
        printf("%d\n", -ans);
    }
    return 0;
}