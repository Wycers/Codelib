#pragma GCC optimize("O3")
#include <cstdio>
#include <queue>
#include <cstring>
const int N = 2e3 + 10;
const int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
using namespace std;
int n, m;
char mp[N][N];
int ans[N][N];
void readin()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", mp[i]);
}
queue<pair<int, int> > q;
bool inq[N][N];
void bfs()
{   
    while (!q.empty())
        q.pop();
    memset(ans, 0x3f, sizeof ans);
    memset(inq, false, sizeof inq);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mp[i][j] == 'H')
            {
                q.emplace(make_pair(i, j));
                ans[i][j] = 0;
                break;
            }
    int ANS = 0x3f3f3f3f;
    while (!q.empty())
    {
        pair<int, int> now = q.front(); q.pop();
        inq[now.first][now.second] = false;
        for (int i = 0; i < 4; ++i)
        {
            int dx = now.first + d[i][0], dy = now.second + d[i][1];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m || mp[dx][dy] == 'W')
                continue;
            int t = ans[now.first][now.second] + 1 + (mp[dx][dy] == 'B');
            if (t >= ans[dx][dy] || t >= ANS)
                continue;
            ans[dx][dy] = t;
            if (mp[dx][dy] == 'S')
            {
                ANS = min(ANS, t);
                continue;
            }
            if (inq[dx][dy])
                continue;
            q.emplace(make_pair(dx, dy));
            inq[dx][dy] = true;
        }
    }
    printf("%d\n", ANS);
}

int main()
{
    readin();
    bfs();
    return 0;
}