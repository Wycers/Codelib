#include <cstdio>
#include <algorithm>
using namespace std;
 
 
 
char sd[5][5] = 
{
    {'0', '0', '+', '-', '+'},
    {'0', '/', '.', '/', '|'},
    {'+', '-', '+', '.', '+'},
    {'|', '.', '|', '/', '0'},
    {'+', '-', '+', '0', '0'}
};
 
int a, b, c, n, m;
char mp[1000][1000];
void drawt(int x, int y)
{
    x = x - 4;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (sd[i][j] != '0')
                mp[i + x][j + y] = sd[i][j];
}
void draw(int x, int y, int z)
{
    int tx = n - 2 * (a - x);
    int ty = 2 * (a - x) + 1 + 2 * (y - 1);
    for (int i = 1; i <= c; ++i)
        drawt(tx - 2 * (i - 1), ty);
}
void solve()
{
    scanf("%d%d%d", &b, &a, &c);
    n = 0, m = 0;
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
        {
            n = max(n, 2 * c + 3 + 2 * (a - i));
            m = max(m, 2 * j + 3 + 2 * (a - i));
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            mp[i][j] = '.';
     
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            draw(i, j, c);
     
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%c", mp[i][j]);
        puts("");
    }
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}