#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int score[25] = { 0,     0,   0,    0,    0,
                  0, 10000,  36,  720,  360,
                 80,   252, 108,   72,   54, 
                180,    72, 180,  119,   36,
                360,  1080, 144, 1800, 3600};
int a[3][3], b[3][3], used[10], dcnt, dans, cnt, n;
int row[3], col[3], dia[2];
double ans;
inline int tryss(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return score[b[x1][y1] + b[x2][y2] + b[x3][y3]];
}
inline int trys(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (a[x1][y1] && a[x2][y2] && a[x3][y3])
        return score[b[x1][y1] + b[x2][y2] + b[x3][y3]];
    return 0;
}
void dget()
{
    row[0] += tryss(0, 0, 0, 1, 0, 2);
    row[1] += tryss(1, 0, 1, 1, 1, 2);
    row[2] += tryss(2, 0, 2, 1, 2, 2);
    col[0] += tryss(0, 0, 1, 0, 2, 0);
    col[1] += tryss(0, 1, 1, 1, 2, 1);
    col[2] += tryss(0, 2, 1, 2, 2, 2);
    dia[0] += tryss(0, 0, 1, 1, 2, 2);
    dia[1] += tryss(0, 2, 1, 1, 2, 0);
}
void ddfs(int x, int y)
{
    if (y == 3)
    {
        ++x;
        y = 0;
    }
    if (x == 3)
    {
        dget();
        ++dcnt;
        return;
    }
    if (a[x][y] == 0)
    {
        for (int i = 1; i <= 9; ++i)
        {
            if (used[i])
                continue;
            used[i] = true;
            b[x][y] = i;
            ddfs(x, y + 1);
            used[i] = false;
        }
    }
    else 
        ddfs(x, y + 1);
}

inline double get()
{
    long long res = 0;
    res = max(res, 1ll * trys(0, 0, 0, 1, 0, 2));
    res = max(res, 1ll * trys(1, 0, 1, 1, 1, 2));
    res = max(res, 1ll * trys(2, 0, 2, 1, 2, 2));
    res = max(res, 1ll * trys(0, 0, 1, 0, 2, 0));
    res = max(res, 1ll * trys(0, 1, 1, 1, 2, 1));
    res = max(res, 1ll * trys(0, 2, 1, 2, 2, 2));
    res = max(res, 1ll * trys(0, 0, 1, 1, 2, 2));
    res = max(res, 1ll * trys(0, 2, 1, 1, 2, 0));
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(dia, 0, sizeof dia);
    dcnt = 0;
    ddfs(0, 0);
    res *= dcnt;
    for (int i = 0; i < 3; ++i) 
        res = max(res, 1ll * row[i]);
    for (int i = 0; i < 3; ++i) 
        res = max(res, 1ll * col[i]);
    for (int i = 0; i < 2; ++i) 
        res = max(res, 1ll * dia[i]);
    return (double)res / dcnt;
}

void dfs(int x, int y)
{
    if (y == 3)
    {
        ++x;
        y = 0;
    }
    if (x == 3)
    {
        ans += get();
        ++cnt;
        return;
    }
    if (a[x][y] == -1)
    {
        for (int i = 1; i <= 9; ++i)
        {
            if (used[i])
                continue;
            used[i] = true;
            b[x][y] = i;
            dfs(x, y + 1);
            used[i] = false;
        }
    }
    else 
        dfs(x, y + 1);
}
void solve()
{
    char str[3];
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(used, false, sizeof used);
    n = 0;
    for (int i = 0; i < 3; ++i)
    {
        scanf("%s", str);
        for (int j = 0; j < 3; ++j)
            if (str[j] == '*')
                a[i][j] = -1;
            else if (str[j] == '#')
            {
                ++n;
                a[i][j] = 0;
            }
            else 
            {
                a[i][j] = b[i][j] = str[j] - '0';
                used[str[j] - '0'] = true;
            }
    }
    cnt = 0;
    ans = 0.0;
    dfs(0, 0);
    printf("%.8f\n", (double)ans / cnt);
}
int main()
{
    freopen("test.in", "r", stdin);
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}