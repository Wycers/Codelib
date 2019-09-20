#include <cstdio>
#include <cstring>
using namespace std;
const int N = 60;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int n, m;
char mp[N][N], str[N * N];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int t[4], ans; bool use[4];
int sx, sy, ex, ey;
bool judge(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (mp[x][y] == '#')
        return false;
    return true;
}
bool walk(int x, int y)
{
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        int now = str[i] - '0';
        x += d[t[now]][0], y += d[t[now]][1];
        if (judge(x, y) == false)
            return false;
        if (mp[x][y] == 'E')
            return true;
    }
    return false;
}
void dfs(int k)
{
    if (k == 4)
    {
        if (walk(sx, sy))
            ++ans;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (use[i])
            continue;
        use[i] = true;
        t[k] = i;
        dfs(k + 1);
        use[i] = false;
    }
}
void solve()
{
    n = read(); m = read();
    for (int i = 0; i < n; ++i)
        scanf("%s", mp[i]);
    scanf("%s", str);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mp[i][j] == 'S')
            {
                sx = i, sy = j;
                break;
            }
    ans = 0;
    dfs(0);
    printf("%d\n", ans);
}
int main()
{
    int T = read();
    while (T--)
        solve();
    return 0;
}

/*
2
5 6
.....#
S....#
.#....
.#....
...E..
333300012
5 3
...
.S.
###
.E.
...
3
*/