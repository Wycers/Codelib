#include <cstdio>
#include <queue>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 400;
const int M = 20000;
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
void insert(int u, int v, int c)
{
    edge[++cnt] = (edge_){v, head[u], c};
    head[u] = cnt;
}
void Insert(int u, int v, int c)
{
    insert(u, v, c);
    insert(v, u, 0);
}

int n, m, S, T, w[N], a[N], b[N];
void readin()
{
    n = read(); 
    for (int i = 1; i <= n; ++i)
    {
        w[i] = read();
        a[i] = read();
    }
    m = read();
    for (int i = 1; i <= m; ++i)
        b[i] = read();
}

queue<int> q; 
int dis[N]; bool inq[N];
bool spfa()
{
    for (int i = S; i <= T; ++i)
        dis[i] = -1;
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

int dinic()
{
    int ans = 0;
    while (spfa())
        ans += dfs(S, Inf);
	return ans;
}

vector<int> vec;
bool Dfs(int u)
{
    if (u == S)
        return true;
    for (int i = head[u]; i; i = edge[i].next)
        if ((i & 1) == 1 && edge[i].c == 1)
        {
            vec.push_back(edge[i].to);
            if (Dfs(edge[i].to))
                return true;
            vec.pop_back();
        }
    return false;
}
void solve()
{
    S = 0; T = 2 * n + m + 1;
    for (int i = 1; i <= n; ++i)
        if (w[i] == 0)
            Insert(S, i, Inf);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j && a[i] >= w[j]) 
                Insert(n + i, j, 1);

    for (int i = 1; i <= n; ++i)
        Insert(i, n + i, 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] >= b[j])
                Insert(n + i, 2 * n + j, 1);

    for (int j = 1; j <= m; ++j)
        Insert(2 * n + j, T, 1);
    if (dinic() != m)
    {
        puts("impossible");
        return;
    }

    for (int i = 1; i <= m; ++i)
    {
        while (!vec.empty())
            vec.pop_back();
        Dfs(2 * n + i);
        while (!vec.empty())
        {
            if (1 <= vec.back() && vec.back() <= n)
                printf("%d ", vec.back());
            vec.pop_back();
        }
        puts("");
    }
}

int main()
{
    readin();
    solve();
    return 0;
}
