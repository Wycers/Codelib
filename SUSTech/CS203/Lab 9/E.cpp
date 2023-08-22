#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int N = 5e3 + 10;
const int M = 2e4 + 10;
int n, m;
struct Edge
{
    int to, next;
} edge[M];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
int du[N];

priority_queue<int, vector<int>, greater<int> > q, tmp;
void solve()
{
    memset(du, 0, sizeof du);
    memset(head, 0, sizeof head);
    cnt = 0;
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        insert(u, v);
        ++du[v];
    }
    q = tmp; 
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i)
        if (du[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int now = q.top(); q.pop();
        ans.push_back(now);
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (--du[v] == 0)
                q.push(v);
        }
    }
    if (ans.size() != n)
    {
        puts("impossible");
        return;
    }
    for (auto i : ans)
        printf("%d ", i);
    puts("");
}
int main()
{
    while (!tmp.empty())
        tmp.pop();
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}