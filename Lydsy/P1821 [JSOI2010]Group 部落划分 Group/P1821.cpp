#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 1005
using namespace std;
int x[N],y[N],fa[N];
struct edge_
{
    int u,v;
    double w;
}edge[N * N / 2];
int cnt = 0,n,k;
int Find(int k)
{
    return fa[k] == k ? k : fa[k] = Find(fa[k]);
}

double Dis(int i,int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

void Readin()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        for (int j=1;j<=i-1;j++)
        {
            edge[++cnt].u = i;
            edge[cnt].v = j;
            edge[cnt].w = Dis(i,j);
        }
    }
}

bool cmp(const edge_ a,const edge_ b)
{
    return a.w < b.w;
}

void Work()
{
    sort(edge + 1,edge + cnt + 1,cmp);
    for (int i=1;i<=n;i++)
        fa[i] = i;
    for (int i=1;i<=cnt;i++)
    {
        int x = Find(edge[i].u),y = Find(edge[i].v);
        if (x != y)
        {
            if (n > k)
            {
                n --;
                fa[x] = y;
            }
            else
            {
                printf("%.2f\n",edge[i].w);
                return;
            }
        }
    }
}

int main()
{
    Readin();
    Work();
    return 0;
}
