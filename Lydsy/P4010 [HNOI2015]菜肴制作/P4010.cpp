#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
const int N = 100000 + 10;
using namespace std;
int Read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
struct edge_
{
    int to,next;
} edge[N];
int head[N],cnt;
void Insert(int u,int v)
{
    edge[++cnt] = (edge_){v,head[u]};
    head[u] = cnt;
}

int d[N],ans[N],top,n,m;
void Init()
{
    memset(d,0,sizeof(d));
    memset(head,0,sizeof(head));
    cnt = top = 0;
    n = Read();m = Read();
    int u,v;
    for (int i=1;i<=m;i++)
    {
        u = Read(); v = Read();
        Insert(v,u);
        ++d[u];
    }
}

priority_queue<int> q;
void Bfs()
{
    int now,v;
    while (!q.empty())
    {
        now = q.top(); q.pop();
        ans[++top] = now;
        for (int i=head[now];i;i=edge[i].next)
        {
            v = edge[i].to;
            if (!(--d[v]))
                q.push(v);
        }
    }
}
void Solve()
{
    for (int i=1;i<=n;++i)
        if (!d[i])
            q.push(i);
    Bfs();
    if (top != n)
        puts("Impossible!");
    else
    {
        for (int i=n;i;i--)
            printf("%d ", ans[i]);
        puts("");
    }
}

int main()
{
    int T = Read();
    while (T--)
    {
        Init();
        Solve();
    }
    return 0;
}
