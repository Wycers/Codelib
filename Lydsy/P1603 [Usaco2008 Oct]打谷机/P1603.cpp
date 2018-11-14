#include <cstdio>
const int N = 1000 + 10;
using namespace std;
struct edge
{
    int to,next,t;
} e[N * N / 2];
int head[N],cnt = 0;
int n;
void Insert(int u,int v,int t)
{
    e[++cnt] = (edge){v,head[u],t};
    head[u] = cnt;
}

void Readin()
{
    int u,v,t;
    scanf("%d",&n);
    for (int i=1;i<n;++i)
    {
        scanf("%d%d%d",&u,&v,&t);
        Insert(u,v,t);
    }
}

int f[N];
void Dfs(int now,int t)
{
    f[now] = t;
    for (int i=head[now];i;i=e[i].next)
        Dfs(e[i].to,t ^ e[i].t);
}

int main()
{
    Readin();
    Dfs(1,0);
    printf("%d\n",f[n]);
    return 0;
}
