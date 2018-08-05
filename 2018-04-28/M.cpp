#include <cstdio>

const int N = 2 * 100 + 10;
const int M = N * N / 2;
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
int head[N], cnt = 0;
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
void solve()
{
    S = 0; T = 2 * (n + m) + 1; int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (w[i] == 0)
            Insert(S, i, 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j && a[i] > w[j]) 
                Insert(i, j, 1);

    for (int i = 1; i <= n; ++i)
        Insert(i, n + i, 1);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] > b[j])
                Insert(n + i, 2 * n + j, 1);

    for (int j = 1; j <= m; ++j)
        Insert(2 * n + j, 2 * n + m + j, 1);
    
    
}

int main()
{
    readin();
    solve();
    return 0;
}