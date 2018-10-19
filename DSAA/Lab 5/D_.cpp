#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int len, nx[N];
char str[N];
bool judge(int x)
{
    int g = len - x;
    if (strncmp(str, str + g, x) != 0)
        return false;
    g -= x;
    for (int i = x; i <= g; ++i)
        if (strncmp(str, str + i, x) == 0)
            return true;
    return false;
}
void solve()
{
    scanf("%d", &len);
    scanf("%s", str);
    for (int ans = len / 3; ans >= 1; --ans)
        if (judge(ans))
        {
            printf("%d\n", ans);
            return;
        }
    puts("0");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}