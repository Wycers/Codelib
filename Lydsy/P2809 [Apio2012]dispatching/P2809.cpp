#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
int n,m;
int ls[N],rs[N],sz[N],L[N],c[N],dist[N];
long long sum[N];
int root[N];

struct edge_
{
	int to,next;
} edge[N];
int head[N],cnt = 0;

void Insert(int u,int v)
{
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

void Readin()
{
	scanf("%d%d",&n,&m);
	int x;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,c + i,L + i);
		if (x)
			Insert(x,i);
       sum[i] = c[i];
       sz[i] = 1;
	}
}

int Merge(int x,int y)
{
	if (!x || !y)
		return x + y;
	if (c[x] < c[y])
		swap(x,y);
	rs[x] = Merge(rs[x],y);
	if (dist[rs[x]] > dist[ls[x]])
		swap(rs[x],ls[x]);
	dist[x] = dist[rs[x]] + 1;
	sum[x] = sum[ls[x]] + sum[rs[x]] + c[x];
	sz[x] = sz[ls[x]] + sz[rs[x]] + 1;
	return x;
}

long long ans;
void Work(int x)
{
    root[x] = x;
    for(int i=head[x];i;i=edge[i].next)
    {
		Work(edge[i].to);
		root[x] = Merge(root[x],root[edge[i].to]);
	}
    while(sum[root[x]] > m)
		root[x] = Merge(ls[root[x]],rs[root[x]]);
    ans = max(ans,(long long)L[x] * sz[root[x]]);
}

int main()
{
	Readin();
	dist[0] = -1;
	Work(1);
	printf("%lld\n",ans);
	return 0;
	
}
