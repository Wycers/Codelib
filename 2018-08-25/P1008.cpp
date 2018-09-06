#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, a[N][N], f[N][N][2], g[N][N][2];
vector<pair<int, int> > v;
int dp()
{
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            for (int k = 1; k <= n; ++k)
            {
                if (k == i || k == j)
                    continue;
                if (a[i][j] == a[j][k])
                    ++f[i][k][a[i][j]];
                else 
                    ++g[i][k][a[i][j]];
            }
        }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) 
                continue;
            res += f[i][j][0] * f[j][i][0] + f[i][j][1] * f[j][i][1];
            res -= g[i][j][0] * g[j][i][0] + g[i][j][1] * g[j][i][1];
        }
    return res;
}
char str[N];
void solve()
{
    scanf("%d", &n);
    v.clear();
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str);
        for (int j = 0; j < n; ++j)
        {
            if (str[j] == '1')
                a[i][j + 1] = 1;
            if (str[j] == '2')
                v.push_back(make_pair(i, j + 1));
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 0, len = v.size(); i < len; ++i)
        if (v[i].first < v[i].second)
            a[v[i].first][v[i].second] = 1;
        else
            a[v[i].second][v[i].first] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d ", a[i][j]);
        puts("");
    }
    ans = max(ans, dp());
    for (int i = 0, len = v.size(); i < len; ++i)
        if (v[i].first < v[i].second)
            a[v[i].first][v[i].second] = 0;
        else
            a[v[i].second][v[i].first] = 0;
    for (int i = 0, len = v.size(); i < len; ++i)
        if (v[i].first > v[i].second)
            a[v[i].first][v[i].second] = 1;
        else
            a[v[i].second][v[i].first] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d ", a[i][j]);
        puts("");
    }
    ans = max(ans, dp());
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