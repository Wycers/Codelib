#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define N 25
using namespace std;
int n,m,K,ne;

struct edge_
{
	int to,next,v;
} edge[N * N];
int head[N];
void Insert(int ne,int s,int t,int w)
{
	edge[ne].to = t;
	edge[ne].v = w;
	edge[ne].next = head[s];
	head[s] = ne;
}


bool flag[N][105];
void Readin()
{
	int s,t,v,d;
	scanf("%d%d%d%d",&n,&m,&K,&ne);
	for (int i=1;i<=ne;i++)
	{
		scanf("%d%d%d",&s,&t,&v);
		Insert(2 * i - 1,s,t,v);
		Insert(2 * i,t,s,v);
	}
	scanf("%d",&d);
	for (int i=1;i<=d;i++)
	{
		scanf("%d%d%d",&v,&s,&t);
		for (int j=s;j<=t;j++)
			flag[v][j] = true;
	}
}

queue<int> q;
bool inq[N];
int Dis[N];
int Spfa(int x,int y)
{
	bool avi[N];
	memset(avi,true,sizeof(avi));
	memset(Dis,0x3f,sizeof(Dis));
	memset(inq,false,sizeof(inq));
	Dis[1] = 0;inq[1] = true;
	q.push(1);
	for (int i=1;i<=m;i++)
		for (int j=x;j<=y;j++)
			if (flag[i][j])
				avi[i] = false;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i=head[u];i;i=edge[i].next)
		{
			int v = edge[i].to,w = edge[i].v;
			if (avi[v] && Dis[v] > Dis[u] + w)
			{
				Dis[v] = Dis[u] + w;
				if (!inq[v])
				{
					q.push(v);
					inq[v] = true;
				}
			}
		}
		inq[u] = false;
	}
	return Dis[m];
}

long long a[105][105],f[105];
void Work()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j] = Spfa(i,j);
	for (int i=1;i<=n;i++)
	{
		f[i] = (long long)a[1][i] * i;
		for (int j=0;j<i;j++)
			f[i] = min(f[i],f[j] + K + a[j + 1][i] * (i - j));
	}
	printf("%d\n",f[n]);
}

int main()
{
	Readin();
	Work();
	return 0;
}
