#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000005
using namespace std;
int n,a[N],fa[N],dis[N],l[N],r[N];
bool die[N];
int Read()
{
	int x = 0,f = 1;char ch = getchar();
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
	return x * f;
} 

void Readin()
{
	n = Read();
	for (int i=1;i<=n;i++)
	{
		fa[i] = i;
		die[i] = false;
		a[i] = Read();
		printf("%d\n",a[i]);
	}
}

int Find(int k)
{
	return fa[k] == k ? k : fa[k] = Find(fa[k]);
}

int Merge(int x,int y)
{
	if (!x || !y)
		return x + y;
	if (a[x] > a[y])
		swap(x,y);
	r[x] = Merge(r[x],y);
	if(dis[r[x]] > dis[l[x]])
		swap(l[x],r[x]);
	dis[x] = dis[r[x]] + 1;
	return x;
}

void Solve()
{
	char opt[3];int x,y;
	dis[0] = -1;
	for (int m=Read();m--;)
	{
		scanf("%s",opt);
		if (opt[0] == 'M')
		{
			x = Read();y = Read();
			if (die[x] || die[y])
				continue;
			int p = Find(x),q = Find(y);
			if (p != q)
				fa[p] = fa[q] = Merge(p,q);
		}
		else
		{
			x = Read();
			if (die[x])
			{
				puts("0");
				continue;
			}
			int p = Find(x);
			printf("%d\n",a[p]);
			die[fa[p]] = true;
			fa[p] = Merge(l[p],r[p]);
			fa[fa[p]] = fa[p];
		}
	}
}
int main()
{
	Readin();
	Solve();
	return 0;
}
