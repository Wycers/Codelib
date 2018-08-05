#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100;
int n, m;
bool mp[N][N];
void readin()
{
    char ch[N];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", ch);
        for (int j = 0; j < m; ++j)
            mp[i][j] = ch[j] == '#' ? true : false;
    }
}
int vis[N][N];
int ans;
bool judge(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}
void work(int k, int x, int y)
{
    vis[x][y] = k;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (judge(x + i, y + j) && mp[x + i][y + j] && !vis[x + i][y + j])
                work(k, x + i, y + j);
}
void work()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!vis[i][j] && mp[i][j])
                work(++ans, i, j);
    printf("%d\n", ans);
}
int main()
{
    readin();
    work();
    return 0;
}