#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define N 5005
using namespace std;
int x[N * N + 10];
int t[N * N + 10];
int up[N],down[N],ans[N * 2],top = 0;
long long a,b,c,d;
int n,m,nm,k;

void Readin()
{
	scanf("%d%lld%lld%lld%lld",&x[0],&a,&b,&c,&d);
	scanf("%d%d%d",&n,&m,&k);
	nm = n * m;
}

void Init()
{
	for (int i=1;i<=nm;i++)
		x[i] = (a * x[i - 1] * x[i - 1] + b * x[i - 1] + c) % d,t[i] = i;
	int p,q;
	for(int i=1;i<=nm;i++)
		swap(t[i],t[(x[i] % i) + 1]);
	while (k--)
	{
		scanf("%d%d",&p,&q);
		swap(t[p],t[q]);
	}
}

void Add(int x,int y)
{
	for(int i=1;i<=n;i++)
		if(i < x)
			up[i] = min(y,up[i]);
		else if(i > x)
			down[i] = max(y,down[i]);
}
void Work()
{
	memset(up,127/3,sizeof(up));
	for (int i=1;i<=nm;i++)
		x[t[i]] = i;
	int p,q;
	for(int i=1;i<=nm;i++)
	{
		p = x[i] / m;
		q = x[i] % m;
		if(q)
			p++;
		else
			q = m;
		if(down[p] <= q && q <= up[p])
		{
			Add(p,q);
			ans[++top]=i;
			if(top == n + m - 1)
				break;
		}
	}
	for(int i=1;i<=top;i++)
		printf("%d%c",ans[i],(i != top) ? ' ' : '\n');
}
	
int main()
{
	Readin();
	Init();
	Work();
	return 0;
}
