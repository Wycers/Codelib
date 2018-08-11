#include <cstdio>
#include <cstring>
const int N = 1e3 + 10;
int n, ans[N], p[N]; bool vis[N];
int solve(int s)
{
    int now = s;
    memset(vis, false, sizeof vis);
    while (vis[now] == false)
    {
        vis[now] = true;
        now = p[now];
    }
    ans[s] = now;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", p + i);
    for (int i = 1; i <= n; ++i)
        solve(i);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    return 0;
}