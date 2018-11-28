#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
const int N = 1e3 + 10;
const int M = 1e5 + 10;
using namespace std;
struct edge
{
    int to,next,l;
} e[M];
int head[N],cnt = 0;
int n;
void Insert(int u,int v,int w)
{
    e[++cnt] = (edge){v,head[u],w};
    head[u] = cnt;
}
void Read(int &x);
void Readin()
{
    int m1,m2,u,v,d;
    Read(n); Read(m1); Read(m2);
    for (int i=1;i<=m1;++i)
    {
        Read(u); Read(v); Read(d);
        if (u > v) swap(u,v);
        Insert(u,v,d);
    }
    for (int i=1;i<=m2;++i)
    {
        Read(u); Read(v); Read(d);
        if (u > v) swap(u,v);
        Insert(v,u,-d);
    }
}

queue<int> q;
int Dis[N],cir[N];
bool inq[N];
bool Spfa()
{
    memset(inq,false,sizeof(inq));
    memset(cir,false,sizeof(cir));
    memset(Dis,0x3f,sizeof(Dis));
    q.push(1); Dis[1] = 0; inq[1] = true;
    int now,v;
    bool flag = false;
    while (!q.empty())
    {
        now = q.front(); q.pop();
        for (int i=head[now];i;i=e[i].next)
        {
            v = e[i].to;
            if (Dis[now] + e[i].l < Dis[v])
            {
                Dis[v] = Dis[now] + e[i].l;
                if (++cir[v] > n)
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
    for (int i=1;i<=n;++i)
        printf("%d ",Dis[i]);
    printf("\n");
    return true;
}
int main()
{
    Readin();
    if (!Spfa())
        puts("-1");
    else if (Dis[n] == 0x3f3f3f3f)
        puts("-2");
    else printf("%d\n",Dis[n]);
    return 0;
}

void Read(int &x)
{
    x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9')
        x = x * 10 + ch - 48,ch = getchar();
}
