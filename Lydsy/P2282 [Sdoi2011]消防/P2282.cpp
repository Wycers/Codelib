#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define N 300005
using namespace std;

struct edge_
{
	int to,next,w;
} edge[2 * N];
int head[N],cnt = 0;
int n,m;

void Insert(int u,int v,int w)
{
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

void Readin()
{
	int u,v,w;
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		Insert(u,v,w);
		Insert(v,u,w);
	}
}

bool inq[N];
int Dis[N],fa[N];
queue<int> q;
int Bfs(int s)
{
	int Max = 0;
	memset(Dis,0,sizeof(Dis));
	fa[s] = -1;
	inq[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int now = q.front();q.pop();
		for (int i=head[now];i;i=edge[i].next)
		{
			int v = edge[i].to;
			if (inq[v])
				continue;
			Dis[v] = Dis[now] + edge[i].w;
			Max = max(Dis[v],Max);
			fa[v] = now;
			inq[v] = true;
			q.push(v);
		}
	}
	return Max;
}

int seq[N],top = 0;
int f[N],g[N],h[N];
void Work()
{
	int s = 1,t = 1;
	memset(inq,false,sizeof(inq));
	Bfs(1);
	for (int i=1;i<=n;i++)
		if (Dis[i] > Dis[s])
			s = i;
		
	memset(inq,false,sizeof(inq));
	Bfs(s);
	for (int i=1;i<=n;i++)
		if (Dis[i] > Dis[t])
			t = i;
	
	memset(inq,false,sizeof(inq));
	while (t != -1)
	{
		seq[++top] = t;
		inq[t] = true;
		t = fa[t];
	}
	//-----求直径
	
	for (int i=1;i<=top;i++)
		f[i] = Dis[seq[1]] - Dis[seq[i]];
	
	for (int i=1;i<=top;i++)
		g[i] = Dis[seq[i]];
	g[top] = 0;
	
	for (int i=1;i<=top;i++)
		h[i] = Bfs(seq[i]);
	//求到直径上各点的最大距离
	
}

int st[N],pos[N],L,R;
int main()
{
	Readin();
    Work();
    int l=1,r=0,ans=0x3f3f3f3f;
    for(l=1;l<=top;l++)
    { 
        while(r < top && f[r + 1] - f[l] <= m)
        {
            r++;
            while(L <= R && st[R] < h[r])
				R--;
            st[++R] = h[r];
            pos[R] = r;
        }
        ans = min(ans,max(max(f[l],g[r]),st[L]));
        if(pos[L] <= l)
			L++;
    }
    printf("%d\n",ans);
    return 0;
}
