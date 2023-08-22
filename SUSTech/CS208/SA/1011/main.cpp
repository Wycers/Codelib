#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
const int M = 2e5 + 10;

int n, m;

struct E
{
    int to, next, w;
} edge[M];
int head[N], cnt = 0;

void insert(int u, int v, int w)
{
    edge[++cnt] = (E){v, head[u], w};
    head[u] = cnt;
}

inline int cal(int a, int b, int t)
{
    if (b == 0)
        return 0x3f3f3f3f;
    t %= (a + b);
    return max(0, a - t);
}

int a[N], b[N], f[N];

queue<int> q;
bool inq[N];

int main()
{
    //    freopen("test.in", "r", stdin);

    scanf("%d%d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        insert(u - 1, v - 1, w);
        //        insert(v - 1, u - 1, w);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", a + i, b + i);
    }

    memset(inq, false, sizeof inq);
    memset(f, 0x3f, sizeof f);
    q.push(0);
    inq[0] = true;
    f[0] = 0;
    while (!q.empty())
    {
        int now = q.front();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to, w = edge[i].w;
            if (b[v] == 0)
                continue;
            int cost = f[now] + w + cal(a[v], b[v], f[now] + w);
            if (f[v] > cost)
            {
                f[v] = cost;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
        q.pop();
        inq[now] = false;
    }
    cout << f[n - 1] << endl;
    return 0;
}
