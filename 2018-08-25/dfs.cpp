#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, s[N][N];vector<pair<int, int> > v;

int check()
{
    int ans = 0;
    for (int a = 0; a < n; ++a)
    {
        for (int b = 0; b < n; ++b)
        {
            if (b == a)
                continue;
            for (int c = 0; c < n; ++c)
            {
                if (c == a || c == b)
                    continue;
                for (int d = 0; d < n; ++d)
                {
                    if (d == a || d == b || d == c)
                        continue;
                    if (s[a][b] == s[b][c] && s[b][c] == s[c][d] && s[c][d] == s[d][a])
                        ++ans;
                    if (s[a][b] != s[b][c] && s[b][c] != s[c][d] && s[c][d] != s[d][a])
                        --ans;
                }
            }
        }
    }
    return ans;
}
char str[N];
int ans = 0;
void dfs(int now)
{
    if (now == v.size())
    {
        // for (int i = 1; i <= 5; ++i)
        // {
        //     for (int j = 1; j <= 5; ++j)
        //         printf("%d ", s[i][j]);
        //     puts("");
        // }
        ans = max(ans, check());
        return;
    }
    for (int i = 0; i <= 1; ++i)
    {
        s[v[now].first][v[now].second] = i;
        s[v[now].second][v[now].first] = i ^ 1;
        dfs(now + 1);
    }
}
void solve()
{
    scanf("%d", &n);
    v.clear();
    memset(s, 0, sizeof s);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str);
        for (int j = 0; j < n; ++j)
        {
            if (str[j] == '1')
                s[i][j + 1] = 1;
            if (str[j] == '2' && i < j + 1)
                v.push_back(make_pair(i, j + 1));
        }
    }
    ans = 0;
    dfs(0);
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