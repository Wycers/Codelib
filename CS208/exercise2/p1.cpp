#pragma GCC optimize("O3")
#include <cstdio>
#include <queue>
#include <cstring>
const int N = 2e2 + 10;
const int K = 3e3 + 10;
const int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
using namespace std;
int n, m, k;
char mp[N][N];
int p[K][2];
void readin()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", mp[i]);
    scanf("%d", &k);
    p[0][0] = p[0][1] = 0;
    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i][0] = x;
        p[i][1] = y;
    }
}
queue<pair<int, int> > q, tmp;
int res[N][N];
void bfs(int x, int y)
{   
    q = tmp;
    memset(res, 0x3f, sizeof res);
    q.push(make_pair(x, y));
    res[x][y] = 0;

    while (!q.empty())
    {
        pair<int, int> now = q.front(); q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int dx = now.first + d[i][0], dy = now.second + d[i][1];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m || mp[dx][dy] == 'w' || res[dx][dy] != 0x3f3f3f3f)
                continue;
            res[dx][dy] = res[now.first][now.second] + 1;
            q.emplace(make_pair(dx, dy));
        }
    }
}
int work()
{
    while (!tmp.empty())
        tmp.pop();
    int ans = 0;
    for (int i = 1; i <= k; i += 2)
    {
        bfs(p[i][0], p[i][1]);
        if (res[p[i - 1][0]][p[i - 1][1]] == 0x3f3f3f3f)
            return puts("-1");
        if (res[p[i + 1][0]][p[i + 1][1]] == 0x3f3f3f3f)
            return puts("-1");
        ans += res[p[i - 1][0]][p[i - 1][1]];
        if (i + 1 <= k)
            ans += res[p[i + 1][0]][p[i + 1][1]];
    }
    printf("%d\n", ans);
}
int main()
{
    readin();
    work();
    return 0;
}

/*
4 4
rwrw
rrwr
wrrr
rrww
2
3 0
2 2
*/