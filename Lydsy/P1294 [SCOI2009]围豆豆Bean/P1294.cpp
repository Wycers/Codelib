#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 15;
const int Inf = 0x3f3f3f3f;
const int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n, m, d, val[N], ax[N], ay[N], ans = 0;
char mp[N][N];
//Struct
struct data
{
	int x, y, val;
};
//Code
void Init()
{
	n = read(); m = read(); d = read();
	for (int i = 0; i < d; ++i)
		val[i] = read();
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", mp[i] + 1);
		for (int j = 1; j <= m; ++j)
			if ('1' <= mp[i][j] && mp[i][j] <= '9')
				ax[mp[i][j] - '1'] = i, ay[mp[i][j] - '1'] = j;
	}
}
queue<data> q;
int f[15][15][(1 << 10)];
bool vis[15][15][(1 << 10)];
int Change(data k, int x, int y)
{
	for (int i = 0; i < d; ++i)
        if (y > ay[i] && ((k.x <= ax[i] && x > ax[i] ) || (k.x > ax[i] && x <= ax[i])))
             k.val = (k.val ^ (1 << i));
    return k.val;
}
void Bfs(int fx, int fy)
{
	Clr(vis, false); Clr(f, -1);
    q.push((data){fx, fy, 0});
    f[fx][fy][0] = 0; vis[fx][fy][0] = true;
    int x, y, v, dx, dy;
	while (!q.empty())
	{
		data now = q.front(); q.pop();
		x = now.x; y = now.y; v = now.val;
        vis[x][y][v] = false;
        for (int k = 0; k < 4; ++k)
        {
            dx = x + D[k][0]; dy = y + D[k][1];
            if (dx < 1 || dx > n || dy < 1 || dy > m || mp[dx][dy] != '0')
            	continue;
            int nxt = Change(now, dx, dy);
            if (f[dx][dy][nxt] == -1 || f[dx][dy][nxt] > f[x][y][v] + 1) 
            {
                f[dx][dy][nxt] = f[x][y][v] + 1;
                if (!vis[dx][dy][nxt])
                {
                	q.push((data){dx, dy, nxt});
                    vis[dx][dy][nxt] = true;   
                }
            }
        }
	}
    for (int i = 0; i < (1 << d); ++i)
    {
        if (f[fx][fy][i] == -1)
			continue;
        int t = -f[fx][fy][i];
        for (int j = 0; j < d; ++j)
            if (((i >> j) & 1) == 1)  t += val[j];
        ans = max(ans, t);
    }
}
void Work()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (mp[i][j] == '0')
				Bfs(i, j);
	printf("%d\n", ans);
}
int main()
{
	Init();
	Work();
    return 0;
}


