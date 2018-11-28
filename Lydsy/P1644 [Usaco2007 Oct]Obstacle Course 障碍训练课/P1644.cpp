#include <cstdio>
#define N 105
using namespace std;
const int d[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
char mp[N][N];
int x1,y1,x2,y2,n;

void Readin()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",mp[i] + 1);
		for (int j=1;j<=n;j++)
		{
			if (mp[i][j] == 'A')
				x1 = i,y1 = j;
			if (mp[i][j] == 'B')
				x2 = i,y2 = j;
		}
	}
}

int ans = 0x7fffffff;
bool vis[N][N];

bool Judge(int x,int y)
{
	if (x < 1 || x > n || y < 1 || y > n || vis[x][y])
		return false;
	return true;
}

void Dfs(int x,int y,int k,int l)
{
	if (k > ans)
		return;
	if (x == x2 && y == y2)
	{
		ans = k;
		return;
	}
	vis[x][y] = true;
	for (int i=0;i<4;i++)
	{
		int dx = x + d[i][0];
		int dy = y + d[i][1];
		if (Judge(dx,dy))
		{
			if (x == x1 && y == y1)
				l = i;
			Dfs(dx,dy,k + (i != l),i);
		}
	}
	vis[x][y] = false;
}

int main()
{
	Readin();
	Dfs(x1,x2,0,1);
	return 0;
}
