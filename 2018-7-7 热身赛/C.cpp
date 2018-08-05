#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e4 + 10;
const int M = 2e4 + 10;
int n, m;
int fa[N];
int a[N], b[N]; char ch[N];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

struct Edge
{
    int to, next;
} edge[M];
int head[N], cnt = 0, deal;
int pre[N];
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
queue<int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i)
            fa[i] = i;
        memset(head, 0, sizeof head);
        memset(pre, 0, sizeof pre);
        cnt = deal = 0;
        for (int i = 1; i <= m; ++i)
            cin >> a[i] >> ch[i] >> b[i];
        for (int i = 1; i <= m; ++i)
            if (ch[i] == '=')
            {
                int x = find(a[i]);
                int y = find(b[i]);
                if (x == y)
                    continue;
                fa[x] = y;
                ++deal;
            }
        for (int i = 1; i <= m; ++i)
        {
            if (ch[i] == '=')
                continue;
            if (ch[i] == '<')
                swap(a[i], b[i]);
            int x = find(a[i]);
            int y = find(b[i]);
            insert(x, y);
            ++pre[y];
        }
        bool uncertain = false;
        for (int i = 0; i < n; ++i)
            if (pre[i] == 0 && find(i) == i)
                q.push(i);
        while (!q.empty())
        {
            if (q.size() > 1)
                uncertain = true;
            int now = q.front(); q.pop();
            ++deal;
            for (int i = head[now]; i; i = edge[i].next)
            {
                int v = edge[i].to;
                if (--pre[v] == 0)
                    q.push(v);
            }
        }
        if (deal < n)
            puts("CONFLICT");
        else if (uncertain)
            puts("UNCERTAIN");
        else
            puts("OK");
    }
    return 0;
}