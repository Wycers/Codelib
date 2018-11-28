#include <cstdio>
#include <algorithm>
#define N 505
using namespace std;

int n,m,s,t;

struct Set_
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
	bool Query(int a,int b)
	{
		int x = Find(a);
		int y = Find(b);
		if (x == y)
			return true;
		else 
			return false;
	}
	
	void Insert(int a,int b) // 0/1 - Not/In the same;0 - 
	{
		int x = Find(a);
		int y = Find(b);
		fa[x] = y;
	}
} S;

struct edge_
{
	int u,v,w;
} edge[5005];

bool cmp(const edge_ a,const edge_ b)
{
	return a.w < b.w;
}

int Gcd(int x,int y)
{
	return y == 0 ? x : Gcd(y,x % y);
}

void Readin()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	scanf("%d%d",&s,&t);
}

void Work()
{
	sort(edge + 1,edge + m + 1,cmp);
	int start = 1,i,Max,Min;
	int ansmx = 1,ansmn = 0;
	while (start <= m)
	{
		Max = -1;Min = -1;
		S.Init();
		for (i=start;i<=m;i++)
		{
			S.Insert(edge[i].u,edge[i].v);
			if (S.Query(s,t))
			{
				Max = edge[i].w;
				break;
			}
		}
		if (Max == -1)
		{
			if (!ansmn)
			{
				printf("IMPOSSIBLE\n");
				return;
			}
			break;
		}
		
		S.Init();
		for (;i>=1;i--)
		{
			S.Insert(edge[i].u,edge[i].v);
			if (S.Query(s,t))
			{
				Min = edge[i].w;
				break;
			}
		}
		start = i + 1;
		if(Min == -1)
		{
			if (!ansmn)
			{
				printf("IMPOSSIBLE\n");
				return;
			}
			break;
		}
		int r = Gcd(Max,Min);
		Max /= r;Min /= r;
		if (ansmx * Min > ansmn * Max)
		{
			ansmx = Max;
			ansmn = Min;
		}
	}
	if (ansmn == 1)
		printf("%d\n",ansmx);
	else
		printf("%d/%d",ansmx,ansmn);
}
int main()
{
	Readin();
	Work();
	return 0;
}
	
