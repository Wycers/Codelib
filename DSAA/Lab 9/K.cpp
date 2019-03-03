#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define Clr(x) memset(x,0x00,sizeof(x))
using namespace std;
const int N = 1e5 + 10;
const int Inf = 0x3f3f3f3f;

int n, to[N];
struct Tarjan
{
    int dfn[N], low[N], scc[N], sz[N], scnt, dfsc;
    bool ins[N];
    void init()
    {
        dfsc = scnt = 0;
        Clr(dfn);
        Clr(low);
        Clr(scc);
        Clr(sz);
    }
    stack<int> s;
    void tarjan(int u)
    {
        dfn[u] = low[u] = ++dfsc;
        ins[u] = true;
        s.push(u);
        int v = to[u];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
            low[u] = min(low[u], dfn[v]);
        int now;
        if (low[u] == dfn[u])
        {
            ++scnt;
            while (true)
            {
                ++sz[scnt];
                now = s.top();
                s.pop();
                scc[now] = scnt;
                ins[now] = false;
                if (now == u)
                    break;
            }
        }
    }
    void work()
    {
        for (int i = 1; i <= n; ++i)
            if (!scc[i])
                tarjan(i);
    }
    long long getans()
    {
        sort(sz + 1, sz + scnt + 1);
        
        sz[scnt - 1] += sz[scnt];
        long long res = 0;
        for (int i = 1, t = max(scnt - 1, 1); i <= t; ++i)
            res += 1ll * sz[i] * sz[i];
        return res;
    }
} T;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", to + i);

    T.init();
    T.work();
    
    printf("%lld\n", T.getans());
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
