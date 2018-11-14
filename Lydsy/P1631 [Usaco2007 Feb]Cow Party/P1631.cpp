#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
const int N = 1000 + 10;
const int M = 100000 + 10;
using namespace std;
struct edge
{
    int to,next,l;
} e1[M],e2[M];
int h1[N],h2[N],cnt = 0;
void Insert(int u,int v,int w)
{
    e1[++cnt] = (edge){v,h1[u],w};
    e2[cnt]   = (edge){u,h2[v],w};
    h1[u] = cnt;h2[v] = cnt;
}
int n,m,x;
void Readin()
{
    int u,v,w;
    scanf("%d%d%d",&n,&m,&x);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        Insert(u,v,w);
    }
}
int Dis1[N],Dis2[N];
queue<int> q;
bool inq[N];
void Spfa(int *dis,edge *e,int *head)
{
    memset(inq,false,sizeof(inq));
    q.push(x);
    dis[x] = 0;
    inq[x] = true;
    int now,v;
    while (!q.empty())
    {
        now = q.front();q.pop();
        for (int i=head[now];i;i=e[i].next)
        {
            v = e[i].to;
            if (dis[v] > dis[now] + e[i].l)
            {
                dis[v] = dis[now] + e[i].l;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
            }
        }
        inq[now] = false;
    }
}
void Work()
{
    memset(Dis1,0x3f,sizeof(Dis1));
    Spfa(Dis1,e1,h1);
    memset(Dis2,0x3f,sizeof(Dis2));
    Spfa(Dis2,e2,h2);
    int ans = 0;
    for (int i=1;i<=n;i++)
        if (Dis1[i] + Dis2[i] > ans)
            ans = Dis1[i] + Dis2[i];
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
