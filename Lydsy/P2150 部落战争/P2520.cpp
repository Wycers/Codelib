#include <cstdio>
#include <cstring>
const int N = 50 + 10;
using namespace std;
int id[N][N];
int tot,n,m,r,c;
void Readin()
{
    scanf("%d%d%d%d",&n,&m,&r,&c); getchar();
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            id[i][j] = getchar() == '.' ? ++tot : 0;
        getchar();
    }
}
struct edge
{
    int to,next;
} e[4 * N * N];
int head[N * N],cnt = 0;
void Insert(int u,int v)
{
    e[++cnt] = (edge){v,head[u]};
    head[u] = cnt;
}
void Try(int u,int x,int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return;
    if (id[x][y])
        Insert(u,id[x][y]);
}
void Init()
{
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (id[i][j])
            {
                Try(id[i][j],i + r,j + c);
                Try(id[i][j],i + r,j - c);
                Try(id[i][j],i + c,j + r);
                Try(id[i][j],i + c,j - r);
            }
}
bool vis[N * N];
int from[N * N];
bool Match(int k)
{
    int v;
    vis[k] = true;
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
void Hungary()
{
    memset(from,-1,sizeof(from));
    int ans = 0;
    for (int i=1;i<=tot;++i)
    {
        memset(vis,false,sizeof(vis));
        if (Match(i))
            ++ans;
    }
    printf("%d\n",tot - ans);
}
int main()
{
    Readin();
    Init();
    Hungary();
}
