#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define Clr(x) memset(x,0x00,sizeof(x))
using namespace std;
const int N = 2e4 + 10;
const int M = 5e4 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct edge
{
    int to, next;
} e[M];
int head[N], cnt;
void insert(int u, int v)
{
    e[++cnt] = (edge){v, head[u]};
    head[u] = cnt;
}
int n, m;
struct Tarjan
{
    int dfn[N], low[N], scc[N], scnt, dfsc;
    bool ins[N];
    void init()
    {
        dfsc = cnt = scnt = 0;
        Clr(dfn);
        Clr(low);
        Clr(head);
        Clr(scc);
    }
    stack<int> s;
    void tarjan(int u)
    {
        dfn[u] = low[u] = ++dfsc;
        ins[u] = true;
        s.push(u);
        int v;
        for (int i = head[u]; i; i = e[i].next)
        {
            v = e[i].to;
            if (!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (ins[v])
                low[u] = min(low[u], dfn[v]);
        }
        int now;
        if (low[u] == dfn[u])
        {
            ++scnt;
            while (true)
            {
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
} T;
int ind[N], outd[N];
void solve()
{
    T.init();

    n = read(); m = read();
    for (int i = 1; i <= m; ++i)
    {
        int u = read();
        int v = read();
        insert(u, v);
    }

    T.work();
    
    memset(ind, 0, sizeof ind);
    memset(outd, 0, sizeof outd);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = head[i]; j; j = e[j].next)
        {
            int v = e[j].to;
            if (T.scc[v] == T.scc[i])
                continue;
            ++outd[T.scc[i]];
            ++ind[T.scc[v]];
        }
    }

    int inc = 0, outc = 0;
    for (int i = 1; i <= T.scnt; ++i)
    {
        inc += (ind[i] == 0);
        outc += (outd[i] == 0);
    }
    printf("%d\n", T.scnt > 1 ? max(inc, outc) : 0);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
