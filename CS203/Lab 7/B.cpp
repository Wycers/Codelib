#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Edge 
{
    int to, next;
} edge[N];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
int n, fa[N], val[N], num[N], mn[N], mx[N];
void dfs(int now)
{
    mn[now] = mx[now] = val[now];
    for (int i = head[now]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        dfs(v);
        mn[now] = min(mn[now], mn[v]);
        mx[now] = max(mx[now], mx[v]); 
    }
}
bool checkSearchTree(int now)
{
    if (num[now] > 2)
        return false;
    if (num[now] == 0)
        return true;
    int x = 0, y = 0;
    for (int i = head[now]; i; i = edge[i].next)
    {
        if (x)
            y = edge[i].to;
        else
            x = edge[i].to;
    }
    if (num[now] == 1)
    {
        if (mx[x] < val[now])
            return checkSearchTree(x);
        if (val[now] < mn[x])
            return checkSearchTree(x);
        return false;
    }
    if (mx[x] < val[now] && val[now] < mn[y])
        return checkSearchTree(x) && checkSearchTree(y);
    if (mx[y] < val[now] && val[now] < mn[x])
        return checkSearchTree(x) && checkSearchTree(y);
    return false;
}
bool solve()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
        scanf("%d", val + i);
    memset(fa, 0, sizeof fa);
    memset(head, 0, sizeof head);
    memset(num, 0, sizeof num);
    cnt = 0;
    for (int i = 1, f, s; i < n; ++i)
    {
        scanf("%d%d", &f, &s);
        insert(f, s);
        fa[s] = f;
        ++num[f];
    }
    int root = 1;
    while (fa[root])
        root = fa[root];
    dfs(root);
    return checkSearchTree(root);
}
int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: %s\n", i, solve() ? "YES" : "NO");
    return 0;
}