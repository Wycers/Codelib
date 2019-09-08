#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <bitset>
#include <memory>
#include <cstdio>
#include <utility>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#pragma optimize("-O3")

#ifdef Wavator

#define Debug(...) fprintf(stderr, __VA_ARGS__);

#else

#define Debug(...) 98;

#define cerr   \
    if (false) \
    cout

#endif

typedef long long ll;

template <typename A>
inline void read(A &x)
{
    bool f = false;
    x = 0;
    char c;
    for (c = getchar(); !isdigit(c); c = getchar())
    {
        if (c == '-')
        {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar())
    {
        x = (x << 1) + (x << 3) + c - '0';
    }
    if (f)
    {
        x = -x;
    }
}
#define pb push_back

const int N = 210;
const int M = 1210;
const int Inf = 0x3f3f3f3f;

int n, m, S, T, price[N], value[M];

struct edge_ {
    int to, next, c;
} edge[2 * (N * M + M + N + 2)];
int head[N + M + 2], cnt = 1;
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

queue<int> q; 
int dis[N + M + 2]; bool inq[N + M + 2];
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

void solve()
{
    read(n); read(m);
    S = 0, T = n + m + 1;
    memset(head, 0, sizeof(head));
    cnt = 1;
    int k, t, tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        read(t);
        tot += t;
        Insert(m + i, T, t);
    }
    for (int i = 1; i <= m; ++i)
    {
        read(t);
        Insert(S, i, t);
    }

    for (int i = 1; i <= m; ++i)
    {
        read(k);
        while(k--)
        {
            read(t);
            Insert(i, m + t, Inf);
        }
    }
    printf("%d\n", tot - dinic());
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    read(T);
    while (T--)
        solve();
    return 0;
}