#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, cnt = 0;
int x[1005], y[1005], fa[1005];

struct edge_
{
	int from, to;
	double dis;
} edge[1000005];

bool cmp(const edge_ a,const edge_ b)
{
	return a.dis < b.dis;
}

inline int read()
{
	char ch = getchar();
	int x = 0, f = 1;
	while (ch < '0' || '9' < ch)
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9')
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return f*x;
}


long long Sqr(int k)
{
	return (long long)k*k;
}

double Dis(int a,int b)
{
	return sqrt(Sqr(x[a] - x[b]) + Sqr(y[a] - y[b]));
}

int Find(int k)
{
	return fa[k] == k ? k : fa[k] = Find(fa[k]);
}

void Readin()
{
	n = read();m = read();
	int p,q;
	for (int i=1;i<=n;i++)
	{
		x[i] = read();
		y[i] = read();
		fa[i] = i;
	}
	while (m--)
	{
		p = Find(read());
		q = Find(read());
		fa[p] = q;
	}
}

void Prework()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			edge[++cnt].from = i;
			edge[cnt].to = j;
			edge[cnt].dis = Dis(i, j);
		}
}

void Kruskal()
{
	double ans = 0;int tot = 0;
	sort(edge + 1,edge + cnt + 1,cmp);
	for (int i=1;i<=cnt;i++)
	{
		int p = Find(edge[i].from), q = Find(edge[i].to);
		if (p != q)
		{
			fa[p] = q;
			ans += edge[i].dis;
			tot ++;
			if (tot == n - 1)
				break;
		}
	}
	printf("%.2lf",ans);
}

int main()
{
	Readin();
	Prework();
	Kruskal();
	return 0;
}
