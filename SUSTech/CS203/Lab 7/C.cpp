#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e4 + 10;
struct node
{
    int l, r;
} tr[N];
int n, fa[N], val[N], dep[N], mn[N], mx[N];
void dfs(int now)
{
    dep[now] = 0;
    mn[now] = mx[now] = val[now];
    int l = tr[now].l, r = tr[now].r;
    if (l) 
    {
        dfs(l);
        mn[now] = min(mn[now], mn[l]);
        mx[now] = max(mx[now], mx[l]);
        dep[now] = max(dep[now], dep[l]);
    }
    if (r)
    {
        dfs(r);
        mn[now] = min(mn[now], mn[r]);
        mx[now] = max(mx[now], mx[r]);
        dep[now] = max(dep[now], dep[r]);
    }
    ++dep[now];
}
bool checkSearchTree(int now)
{
    int l = tr[now].l, r = tr[now].r;
    if (l == 0 && r == 0)
        return true;
    if (l && r)
    {
        if (mx[l] < val[now] && val[now] < mn[r])
            return checkSearchTree(l) && checkSearchTree(r);
        return false;
    }
    if (l && mx[l] < val[now])
        return checkSearchTree(l);
    if (r && val[now] < mn[r])
        return checkSearchTree(r);
    return false;
}
bool isAvl(int now)
{
    if (now == 0)
        return true;
    int l = tr[now].l, r = tr[now].r;
    if (isAvl(l) && isAvl(r) && abs(dep[l] - dep[r]) <= 1)
        return true;
    return false;
}
bool solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", val + i);
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
    memset(dep, 0, sizeof dep);
    dfs(root);
    if (checkSearchTree(root) == false)
        return false;
    return isAvl(root);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        puts(solve() ? "Yes" : "No");
    return 0;
}