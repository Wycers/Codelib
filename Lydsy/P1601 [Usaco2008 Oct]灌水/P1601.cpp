#include <cstdio>
#include <algorithm>
#define N 305
using namespace std;
int n;

struct edge_
{
	int u,v,w;
} edge[N * N + N];
int head[N],cnt = 0;
void Insert(int u,int v,int w)
{
	edge[++cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].w = w;
}
bool cmp(const edge_ a,const edge_ b)
{
	return a.w < b.w;
}

struct Set
{
	int fa[N];
	void Init()
	{
		for (int i=1;i<=n;i++)
			fa[i] = i;
	}
	int Find(int k)
	{
		return fa[k] == k ? k : fa[k] = Find(fa[k]);
	}
	bool Insert(int a,int b)
	{
		int x = Find(a);
		int y = Find(b);
		if (x == y)
			return false;
		fa[x] = y;
		return true;
	}
} S;

void Readin()
{
	int t;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		Insert(0,i,t);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&t);
			if (i != j)
				Insert(i,j,t);
		}
}

void Work()
{
	int ans = 0;
	S.Init();
	sort(edge + 1, edge + cnt + 1,cmp);
	for (int i=1;i<=cnt;i++)
	{
		if (S.Insert(edge[i].u,edge[i].v))
			ans += edge[i].w;
	}
	printf("%d\n",ans);
}
		
int main()
{
	Readin();
	Work();
	return 0;
}
