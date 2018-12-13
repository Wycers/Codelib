#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 3e5 + 10;
const int M = 5e5 + 10;
int read()
{
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}
struct node
{
    int now, step, from;
};
struct Edge
{
    int to, next;
} edge[M << 1];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
int n, m, k;
int dis[N], player[N];
queue<node> q, tmp;
void solve()
{
    memset(head, 0, sizeof head);
    memset(dis, 0x3f3f, sizeof dis);
    memset(player, 0, sizeof player);
    cnt = 0;

    n = read(); m = read(); k = read();
    while (m--)
    {
        int x, y;
        x = read(); y = read();
        insert(x, y);
        insert(y, x);
    }
    q = tmp;
    while (k--)
    {
        int tmp = read();
        q.push((node){ tmp, dis[tmp] = 0, player[tmp] = tmp });
    }

    int ans = -1;
    while (!q.empty())
    {
        node tmp = q.front(); q.pop();
        for (int i = head[tmp.now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (player[v])
            {
                if (player[v] == tmp.from)
                    continue;
                ans = dis[v] + tmp.step + 1;
                break;
            }
            else
            {
                q.push((node){ v, dis[v] = tmp.step + 1, player[v] = tmp.from });
            }
        }
        if (ans != -1)
            break;
    }
    printf("%d\n", ans);
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