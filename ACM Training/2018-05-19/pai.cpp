#include <cstdio>
using namespace std;
const int mo = 1e9 + 7;
int n; const int N = 5e3 + 10;
bool now[N];
long long res;
void check()
{
    for (int i = 1; i <= n; ++i)
        printf("%c", now[i] ? 'B' : 'W');
    puts("");
    int ans = 1, l = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (now[i] ^ now[i - 1])
        {
            ans *= i - l;
            l = i;
        }
        if (i == n)
        {
            ans *= i - l + 1;
            break;
        }
    }
    printf("%d\n", ans);
    res += ans;
    res %= mo;
}
void dfs(int k, int x, int y)
{
    if (k == n + 1)
    {
        check();
        return;
    }
    if (k == 1)
    {
        now[k] = true;
        dfs(k + 1, x - 1, y);
        return;
    }
    if (k == n)
    {
        if (y)
        {
            now[k] = false;
            dfs(k + 1, x, y - 1);
        }
        return;
    }
    if (x)
    {
        now[k] = true;
        dfs(k + 1, x - 1, y);
    }
    if (y)
    {  
        now[k] = false;
        dfs(k + 1, x, y - 1);
    }
}
int f[N][N], g[N][N];
int main()
{
    
    g[1][1] = 2;
    for (int i = 2; i <= 10; ++i)
    {
        g[i][1] = i + 1;
        g[1][i] = i + 1;
    }
    for (int i = 2; i <= 10; ++i)
    {
        for (int j = 2; j <= 10; ++j)
            g[i][j] = g[i - 1][j] + g[i][j - 1];
    }
    int x = 2, y = 3;
            res = 0; n = x + y;
            dfs(1, x, y);
            printf("%d\t", res);
    // for (int x = 1; x <= 10; ++x)
    // {
    //     for (int y = 1; y <= 10; ++y)
    //     {
    //         res = 0; n = x + y;
    //         dfs(1, x, y);
    //         printf("%d\t", res);
    //         // printf("%d %d %d\t", x, y, res);
    //     }
    //     puts("");
    // }


    return 0;
}