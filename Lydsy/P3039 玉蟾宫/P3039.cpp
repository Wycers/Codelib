#include <cstdio>
#include <algorithm>
#define N 1005
using namespace std;
bool mp[N][N];
int l[N][N],r[N][N],up[N][N];
int n,m;

char Getchar()
{
	char c = getchar();
	while (c != 'R' && c != 'F')
		c = getchar();
	return c;
}

void Readin()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
			mp[i][j] = Getchar() == 'F';
	}
}

void Work()
{
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
			l[i][j] = mp[i][j] ? l[i][j - 1] + 1 : 0;
		for (int j=n;j>=1;j--)
			r[i][j] = mp[i][j] ? r[i][j + 1] + 1 : 0;
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (mp[i][j] && mp[i - 1][j])
			{
				up[i][j] = up[i - 1][j] + 1;
				l[i][j] = min(l[i][j],l[i - 1][j]);
				r[i][j] = min(r[i][j],r[i - 1][j]);
			}
	int ans = 0;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			ans = max(ans,(r[i][j] + l[i][j] - 1) * (up[i][j] + 1));
	printf("%d\n",3 * ans);
}

int main()
{
	Readin();
	Work();
	return 0;
}
