#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 150010;
int n, Q;
int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
        ch = getchar();
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x;
}

struct Edge
{
    int to, next;
} edge[2 * N];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}

int deep[N], fa[N][20];
void readin()
{
    int u, v;
    n = read();  Q = read();
    for (int i = 1; i <= n - 1; i++)
    {
        u = read(); v = read();
        insert(u, v);
        insert(v, u);
        fa[u][0] = v;
    }
}
void dfs(int now, int f)
{
    for (int i = 1; i < 20; i++)
    {
        if (deep[now] < (1 << i))
            break;
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    }
    for (int i = head[now]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == f)
            continue;
        deep[v] = deep[now] + 1;
        fa[v][0] = now;
        dfs(v, now);
    }
}

void solve()
{
    int x, y, root = 1;
    while (fa[root][0])
        root = fa[root][0];
    deep[root] = 0;
    dfs(root, 0);
    while (Q--)
    {
        x = read(); y = read();
        if (x == y)
        {
            puts("Yes");
            continue;
        }
        if (deep[x] <= deep[y])
        {
            puts("No");
            continue;
        }
        int t = deep[x] - deep[y];
        for (int i = 0; i < 20; i++)
            if (t & (1 << i))
                x = fa[x][i];
        puts(x == y ? "Yes" : "No");

    }
}
int main()
{
    for (int T = read(); T; --T)
    {  
        memset(head, 0, sizeof head);
        memset(fa, 0, sizeof fa);
        cnt = 0;
        readin();
        solve();
    }
    return 0;
}
