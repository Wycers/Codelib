#include <cstdio>
#include <cstring>
#include <queue>
#define N 1005
using namespace std;

struct edge_
{
    int to,next,w;
} edge[N * 20];
int head[N],cnt = 0;

void Insert(int u,int v,int w)
{
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int l = 0,r = 0,ans = -1,n,p,k;

void Readin()
{
    int u,v,w;
    scanf("%d%d%d",&n,&p,&k);
    for (int i=1;i<=p;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        Insert(u,v,w);
        Insert(v,u,w);
        r = w > r ? w : r;
    }
}

queue<int> q;
bool inq[N];
int Dis[N];
bool Spfa(int t)
{
    memset(Dis,0x3f,sizeof(Dis));
    memset(inq,false,sizeof(inq));
    inq[1] = true;
    Dis[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        for (int i=head[now];i;i=edge[i].next)
        {
            int v = edge[i].to,w = edge[i].w;
            if (Dis[now] + (int)(w > t) < Dis[v])
            {
                Dis[v] = Dis[now] + (int)(w > t);
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
        inq[now] = false;
    }
    return (Dis[n] <= k);
}

void Work()
{
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Spfa(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n",ans);
}

int main()
{
    Readin();
    Work();
    return 0;
}
