#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int Inf = 0x3f3f3f3f;
const int N = 5e6 + 10;
const int M = 5e6 + 10;
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
            f += dfs(S, 0x3f3f3f3f);
        }
    }
    return f;
}



int n, m, p, np, sx[160], sy[160], tx[160], ty[160], g[160], mp[1025][15][15][2], nk, key[15][15];
int get(int k, int x, int y)
{
    return k * n * m + m * (x - 1) + y;
}
int main()
{
    freopen("test.in", "r", stdin);
    memset(head, 0, sizeof(head));
    cnt = 1; ans = 0;

    n = read(); m = read(); p = read();
    np = read();
    for (int i = 1; i <= np; ++i)
    {
        sx[i] = read();
        sy[i] = read();
        tx[i] = read();
        ty[i] = read();
        if (sx[i] == tx[i] && sy[i] > ty[i])
            swap(sy[i], ty[i]);
        if (sx[i] > tx[i])
        {
            swap(sx[i], tx[i]);
            swap(sy[i], ty[i]);
        }
        g[i] = read() - 1;
    }
    for (int i = 1; i <= np; ++i)
        if (g[i] == -1)
            g[i] = p;
    memset(mp, -1, sizeof mp);
    for (int i = 1; i <= np; ++i)
        for (int j = 0, len = (1 << p) - 1; j <= len; ++j)
            if (j & (1 << g[i]))
                mp[j][sx[i]][sy[i]][sx[i] == tx[i]] = g[i];
            else 
                mp[j][sx[i]][sy[i]][sx[i] == tx[i]] = p;
            // puts("check");
    for (int k = 0, len = (1 << p) - 1; k <= len; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                int t;
                if (i != n)
                {
                    t = mp[k][i][j][0];
                    if (t == -1 || (k & (1 << t)))
                    {
                        insert(get(k, i, j), get(k, i + 1, j), 1, 1);
                        insert(get(k, i + 1, j), get(k, i, j), 1, 1);
                    }
                }
                if (j != m)
                {
                    t = mp[k][i][j][1];
                    if (t == -1 || (k & (1 << t)))
                    {
                        insert(get(k, i, j), get(k, i, j + 1), 1, 1);
                        insert(get(k, i, j + 1), get(k, i, j), 1, 1);
                    }
                }
            }
    memset(key, 0, sizeof key);
    nk = read();
    for (int i = 1, x, y; i <= nk; ++i)
    {
        x = read(); y = read();
        key[x][y] |= (1 << (read() - 1));
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0, len = (1 << p) - 1; k <= len; ++k)
                if (k != (k | key[i][j]))
                    insert(get(k, i, j), get (k | key[i][j], i, j), 1, 0);
    S = 0; T = get((1 << p) - 1, n, m) + 1;
    insert(S, get(0, 1, 1), 1, 0);
    for (int k = 0, len = (1 << p) - 1; k <= len; ++k)
        insert(get(k, n, m), T, 1, 0);
    zkw();
    printf("%d\n", ans == 0 ? -1 : ans);
    return 0;
}