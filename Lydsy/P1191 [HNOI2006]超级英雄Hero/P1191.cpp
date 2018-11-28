#include <cstdio>
#include <cstring>
#define N 1005
using namespace std;
int n,m;

struct edge_
{
	int to,next;
} edge[N * 2];
int head[N],cnt = 0;
int from[N];
bool vis[N];

void Insert(int u,int v)
{
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

void Readin()
{
	int a,b;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		Insert(i,a);
		Insert(i,b);
	}
}

bool Match(int k)
{
	for (int i=head[k];i;i=edge[i].next)
	{
		int v = edge[i].to;
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

int Hungary()
{
	int ans = 0;
	memset(from,255,sizeof(from));
	for (int i=1;i<=m;i++)
	{
		memset(vis,false,sizeof(vis));
		if (Match(i))
			ans++;
		else
			break;
	}
	return ans;
}
int main()
{
	Readin();
	printf("%d\n",Hungary());
	return 0;
}
