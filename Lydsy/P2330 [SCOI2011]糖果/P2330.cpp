#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 100005
using namespace std;

struct edge_
{
    int to,next,w;
} edge[N * 4];
int head[N],cnt = 0;
void Insert(int u,int v,int w)
{
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int n;bool flag = true;
void Readin()
{
    int k,x,a,b;
    for(scanf("%d%d",&n,&k);k;k--)
    {
        scanf("%d%d%d",&x,&a,&b);
        if (x == 1) { Insert(a,b,0); Insert(b,a,0);}
        else if (x == 2) { if (a == b) flag = false; Insert(a,b,1);}
        else if (x == 3) { Insert(b,a,0);}
        else if (x == 4) { if (a == b) flag = false; Insert(b,a,1);}
        else if (x == 5) { Insert(a,b,0);}
    }
}

queue<int> q;
int Dis[N],vis[N];
bool inq[N];
bool Spfa()
{
    memset(Dis,0,sizeof(Dis));
    memset(vis,0,sizeof(vis));
    memset(inq,false,sizeof(inq));
    q.push(0);
    vis[0] = true;
    inq[0] = true;
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        for (int i=head[now];i;i=edge[i].next)
        {
            int v = edge[i].to,w = edge[i].w;
            if (Dis[now] + w > Dis[v])
            {
                Dis[v] = Dis[now] + w;
                if (++vis[v] >= n)
                    return false;
                if (!inq[v])
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
        inq[now] = false;
    }
    return true;
}
void Work()
{
    long long ans = 0;
    for (int i=n;i>=1;i--)
        Insert(0,i,1);
    if (!Spfa())
        puts("-1");
    else
    {
        for (int i=1;i<=n;i++)
            ans += Dis[i];
        printf("%lld",ans);
    }
}
int main()
{
    Readin();
    if (flag) Work(); else puts("-1");
    return 0;
}
