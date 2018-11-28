#include <cstdio>
#include <cstring>
#define N 205
using namespace std;
int n;
struct edge_
{
    int to,next;
} edge[N * N];
int head[N],cnt;
void Insert(int u,int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void Readin()
{
    int t;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&t);
            if (t)
                Insert(i,j);
        }
}

int from[N];
bool vis[N];
bool Match(int k)
{
    for (int i=head[k];i;i=edge[i].next)
    {
        int v = edge[i].to;
        if (!vis[v])
        {
            vis[v] = true;
            if (from[v] == -1 || Match(from[v]))
            {
                from[v] = k;
                return true;
            }
        }
    }
    return false;
}
bool Hungary()
{
    for (int i=1;i<=n;i++)
    {
        memset(vis,false,sizeof(vis));
        if (!Match(i))
            return false;
    }
    return true;
}

void Init()
{
    cnt = 0;
    memset(head,0,sizeof(head));
    memset(from,255,sizeof(from));
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        Init();
        Readin();
        if (Hungary())
            puts("Yes");
        else
            puts("No");
    }
}
