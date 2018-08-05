#include <cstdio>
#include <map>
const int N = 2e4 + 10;

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

struct Edge()
{
    int to, next;
} edge[2 * N];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = 
}

map<int, int> mp[N];
int fa[N], w[N];
int dfs(int x, int f)
{
    fa[x] = f; 
    for (int i = head[x]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == f)
            continue;
        mp[f][]
        dfs(v, x);
    }
    for (int i = head[x]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == f)
            continue;
        
    }

}
void solve()
{
    memset(head, 0, sizeof(head));
    cnt = 0;
}

int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}