#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
string str;
bool valid(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'w' || c == 'y')
        return false;
    return true;
}
int f[30][30], sum[30], ans;
vector<int> v;
void dfs(int k, int now)
{
    if (k == 26)
    {
        ans = max(ans, now);
        return;
    }
    dfs(k + 1, now);
    if (valid(k + 'a') == false)
        return;
    now += sum[k];
    for (int i = 0, len = v.size(); i < len; ++i)
        now -= 2 * f[v[i]][k];
    v.push_back(k);
    dfs(k + 1, now);
    v.pop_back();
}
void solve()
{
    ans = 0;
    v.clear();
    memset(f, 0, sizeof f);

    cin >> str;
    for (int i = 1, len = str.length(); i < len; ++i)
    {
        if (valid(str[i - 1]) && valid(str[i]) && str[i] != str[i - 1])
        {
            int u = str[i - 1] - 'a';
            int v = str[i] - 'a';
            ++f[u][v];
            ++f[v][u];
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (valid(i + 'a') == false)
            continue;
        sum[i] = 0;
        for (int j = 0; j < 26; ++j)
            sum[i] += f[i][j];
    }
    dfs(0, 0);
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}