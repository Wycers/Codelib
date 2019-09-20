#include <cstdio>
#include <cstring>
using namespace std;
const int N = 150010;
struct node
{
    int l, r;
} tr[N];
int n, fa[N];
bool flag = true;
void dfs(int now, int k)
{
    if (now == 0)
        return;
    if (flag == false)
        return;
    if (k > n)
        flag = false;
    dfs(tr[now].l, k << 1);
    dfs(tr[now].r, k << 1 | 1);
}
void solve()
{
    scanf("%d", &n);
    memset(fa, 0, sizeof fa);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &tr[i].l, &tr[i].r);
        fa[tr[i].l] = i;
        fa[tr[i].r] = i;
    }
    int root = 1;
    while (fa[root])
        root = fa[root];
    flag = true;
    dfs(root, 1);
    puts(flag ? "Yes" : "No");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}