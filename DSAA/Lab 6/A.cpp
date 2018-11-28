#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e4 + 10;
int n;
struct Edge
{
    int to, next;
} edge[N << 1];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
vector<int> ans;
void dfs(int now, int fa)
{
    bool flag = true;
    for (int i = head[now]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        dfs(v, now);
        flag = false;
    }
    if (flag && now != 1)
        ans.push_back(now);
}
void solve()
{
    memset(head, 0, sizeof head); cnt = 0;
    ans.clear();
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        insert(x, y);
        insert(y, x);
    }
    dfs(1, 0);
    sort(ans.begin(), ans.end());
    for (int i = 0, len = ans.size(); i < len; ++i)
        printf("%d ", ans[i]);
    puts("");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}