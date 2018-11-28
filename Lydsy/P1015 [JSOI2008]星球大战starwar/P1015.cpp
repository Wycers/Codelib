#include <cstdio>
#define N 400005
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
int head[N],cnt = 0;

int n,fa[N],tot = 0;
void Insert(int u,int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
void Readin()
{
    int u,v,m;
    n = Read();m = Read();
    while (m --)
    {
        u = Read();v = Read();
        Insert(u,v);
        Insert(v,u);
    }
}

bool used[N];
int r[N],res[N],ans[N];
int Find(int k)
{
    return fa[k] == k ? k : fa[k] = Find(fa[k]);
}
void Connect(int x)
{
    int p = Find(x),v,q;
    for (int i=head[x];i;i=edge[i].next)
    {
        v = edge[i].to;
        if (used[v])
        {
            q = Find(v);
            if (q != p)
            {
                fa[q] = p;
                tot--;
            }
        }
    }
}
void Work()
{
    int d = Read();
    for (int i=1;i<=d;i++)
    {
        r[i] = Read();
        res[r[i]] = true;
    }
    for (int i=0;i<=n;i++)
        fa[i] = i;
    for (int i=0;i<n;i++)
        if (!res[i])
        {
            tot ++;
            Connect(i);
            used[i] = true;
        }
    ans[d + 1] = tot;
    for (int i=d;i>=1;i--)
    {
        tot++;
        Connect(r[i]);
        used[r[i]] = true;
        ans[i] = tot;
    }
    for (int i=1;i<=d+1;i++)
        printf("%d\n",ans[i]);
}
int main()
{
    Readin();
    Work();
    return 0;
}
