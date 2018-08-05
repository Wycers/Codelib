#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e4 + 10;
int n, c, ans;
int trap[N], p[N];
int down[N][5], up[N][5];

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

void dfs(int u, int fa)
{
    up[u][trap[u]] = down[u][trap[u]] = p[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
        for (int j = 0; j < c; ++j)
            for (int k = 0; k + j <= c; ++k)
                ans = max(ans, up[u][j] + down[v][k]);
        for (int k = 0; k < c; ++k)
            for (int j = 0; k + j <= c; ++j)
                ans = max(ans, down[u][j] + up[v][k]);
        for (int j = 0; j <= c; ++j)
            for (int k = 0; k + j < c; ++k)
                ans = max(ans, up[u][j] + up[v][k]);
        for (int j = 0; j <= c; ++j)
        {
            up[u][j + trap[u]] = max(up[u][j + trap[u]], up[v][j] + p[u]);
            if (j != 0)
                down[u][j + trap[u]] = max(down[u][j + trap[u]], down[v][j] + p[u]);
        }
    }
}

int main()
{
    for (int T = read(); T; --T)
    {
        memset(head, 0, sizeof(head));
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        cnt = ans = 0;
        n = read();
        c = read();
        for (int i = 1; i <= n; ++i)
        {
            p[i] = read();
            trap[i] = read();
        }
        for (int i = 1, x, y; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            ++x, ++y;
            insert(x, y);
            insert(y, x);
        }
        dfs(1, 0);
        printf("%d\n", ans);
    }

    return 0;
}