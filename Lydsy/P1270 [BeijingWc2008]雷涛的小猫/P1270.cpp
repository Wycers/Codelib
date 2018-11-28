#include <cstdio>
#include <algorithm>
int n,h,d;
int mp[2005][5005];
int f[5005],g[2005];

inline int Read()
{
	int x = 0;char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9')
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}

void Readin()
{
	int tn,t;
	scanf("%d%d%d",&n,&h,&d);
	for (int i=1;i<=n;i++)
		for (scanf("%d",&tn);tn;tn--)
		{
			t = Read();
			mp[i][t]++;
		}	
}

int Dp()
{
	for (int i=h;i>=1;i--)
	{
		int t = i + d <= h ? f[i + d] : 0;
		for (int j=1;j<=n;j++)
		{
			g[j] = std::max(g[j],t) + mp[j][i];
			f[i] = std::max(f[i],g[j]);
		}
	}
	return f[1];
}

int main()
{
	Readin();
	printf("%d\n",Dp());
	return 0;
}
