#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4;
const int M = 2e5 + 10;
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

struct edge_
{
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

int n, m, S, T, s[N], t[N];
void readin()
{
    n = read(); m = read();
    for (int i = 1; i <= n; ++i)
    {
        s[i] = read();
        t[i] = read();
    }
}

queue<int> q;
int dis[N];
bool inq[N];
bool spfa()
{
    for (int i = S; i <= T; ++i)
        dis[i] = -1;
    memset(inq, false, sizeof(inq));
    q.push(S);
    dis[S] = 0;
    inq[S] = true;
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
        q.pop();
        inq[now] = false;
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
            edge[i].c -= w;
            edge[i ^ 1].c += w;
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

priority_queue<int, vector<int>, greater<int> > pq;
int tag[N];
bool cmp(int a, int b)
{
    return s[a] < s[b];
}
void solve()
{
    int ans1 = 0, ans2 = 0;

    memset(head, 0, sizeof(head));
    cnt = 1;
    
    S = 0; T = 3 * 400 + 1;
    for (int i = 1; i <= m; ++i)
    {
        Insert(S, i, 1);
        for (int j = s[i]; j <= t[i]; ++j)
            Insert(i, j + 400, 1);
    }
    for (int i = 1; i <= 400; ++i)
        Insert(i + 400, i + 800, 1);
    for (int i = m + 1; i <= n; ++i)
    {
        Insert(i, T, 1);
        for (int j = s[i]; j <= t[i]; ++j)
            Insert(j + 800, i, 1);
    }
    ans2 = dinic();


    
    for (int i = 1; i <= n; ++i)
        tag[i] = i;
    sort(tag + 1, tag + n + 1, cmp);
    int now = 1;
    for (int i = 1; i <= 400; ++i)
    {
        while (now <= n && i == s[tag[now]])
            pq.push(t[tag[now++]]);
        
        if (!pq.empty() && i <= pq.top())
        {
            pq.pop();
            ++ans1;
        }
        while (!pq.empty() && i >= pq.top())
            pq.pop();
    }

    printf("%d\n%d\n", ans1, ans2);
}

int main()
{
    readin();
    solve();
    return 0;
}
