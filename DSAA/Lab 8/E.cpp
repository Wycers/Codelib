#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1000;
int n, m;
int mp[N][N];
void readin()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &mp[i][j]);
}
int vis[N][N], ans;
bool judge(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}

void work(int x, int y, int k)
{
    if (vis[x][y])
        return;
    vis[x][y] = k;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (abs(i) != abs(j))
            {
                int ny = y + j;
                if (ny < 0)
                    ny = m - 1;
                if (ny >= m)
                    ny = 0;
                if (judge(x + i, ny) && mp[x + i][ny] == k)
                    work(x + i, ny, k);
            }
}

void work()
{
    memset(vis, 0, sizeof(vis));
    ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!vis[i][j])
            {
                ++ans;
                work(i, j, mp[i][j]);
            }
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--) 
    {
        readin();
        work();
    }
    return 0;
}