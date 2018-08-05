#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char str[16][16];
bool row[16][16], col[16][16];
int mp[16][16], sta[4][4];
int anchor[4][2] = {{0, 0}, {3, 0}, {3, 3}, {0, 3}};
int arrow[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int arcol[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int dight(char c)
{
	if ('0' <= c && c <= '9')
		return c - '0';
	return c - 'A' + 10;
}

bool judge(int x, int y)
{
	int now = sta[x][y];
	int ancx = x * 4 + anchor[now][0], ancy = y * 4 + anchor[now][1];
	for (int i = 0; i < 4; ++i) 
		for (int j = 0; j < 4; ++j)
		{
			int nx = ancx + i * arrow[now][0] + j * arcol[now][0];
			int ny = ancy + i * arrow[now][1] + j * arcol[now][1];
			if (row[x * 4 + i][mp[nx][ny]])
				return false;
			if (col[y * 4 + j][mp[nx][ny]])
				return false;
		}
	return true;
}

void set(int x, int y, bool val)
{
	int now = sta[x][y];
	int ancx = x * 4 + anchor[now][0], ancy = y * 4 + anchor[now][1];
	for (int i = 0; i < 4; ++i) 
		for (int j = 0; j < 4; ++j)
		{
			int nx = ancx + i * arrow[now][0] + j * arcol[now][0];
			int ny = ancy + i * arrow[now][1] + j * arcol[now][1];
			row[x * 4 + i][mp[nx][ny]] = val;
			col[y * 4 + j][mp[nx][ny]] = val;
		}
}

int ans;
void dfs(int x, int y, int k)
{
	if (k >= ans)
		return;
	if (y == 4)
		++x, y = 0;	
	if (x == 4)
	{
		if (k < ans)
			ans = k;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		sta[x][y] = i;
		if (judge(x, y) == false)
			continue;
		set(x, y, true);
		dfs(x, y + 1, k + i);
		set(x, y, false);
	}
}

void solve()
{
	for (int i = 0; i < 16; ++i)
		scanf("%s", str + i);
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j)
			mp[i][j] = dight(str[i][j]);
	memset(sta, 0, sizeof sta);
	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);
	ans = 0x3f3f3f3f; 
	dfs(0, 0, 0);
	printf("%d\n", ans);
}
int main()
{
	freopen("test.in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
