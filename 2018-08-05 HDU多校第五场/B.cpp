#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[15]; int len, n;
char ans[2][15], now[15];

void dfs(int k, int use)
{
    if (k == len)
    {
        if (strcmp(now, ans[0]) < 0)
            strcpy(ans[0], now);
        if (strcmp(now, ans[1]) > 0)
            strcpy(ans[1], now);
        return;
    }
    dfs(k + 1, use);
    for (int i = k + 1; use < n && i < len; ++i)
    {
        if (k == 0 && now[i] == '0')
            continue;
        swap(now[k], now[i]);
        dfs(k + 1, use + 1);
        swap(now[k], now[i]);
    }
}

void solve()
{
    scanf("%s%d", str, &n);
    len = strlen(str);

    strcpy(ans[0], str);
    strcpy(ans[1], str);
    strcpy(now, str);
    dfs(0, 0);
    printf("%s %s\n", ans[0], ans[1]);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}