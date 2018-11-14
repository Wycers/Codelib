#include <cstdio>
#include <cstring>
const int N = 500 + 10;
using namespace std;
struct edge
{
    int to,next;
} e[N * N / 2];
int head[N],cnt = 0;
void Insert(int u,int v)
{
    e[++cnt] = (edge){v,head[u]};
    head[u] = cnt;
}
int n;
void Readin()
{
    int m,u,v;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d",&u,&v);
        Insert(u,v);
    }
}
int from[N];bool vis[N];
bool Match(int k)
{
    int v;
    for (int i=head[k];i;i=e[i].next)
    {
        v = e[i].to;
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
void Work()
{
    int ans = 0;
    memset(from,255,sizeof(from));
    for (int i=1;i<=n;++i)
    {
        memset(vis,false,sizeof(vis));
        if (Match(i))
            ++ans;
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
