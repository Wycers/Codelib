#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int len, nx[N];
char str[N];
bool judge(int x)
{
    int g = len - x;
    if (memcmp(str, str + g, x) != 0)
        return false;
    for (int i = 2 * x - 1; i < g; ++i)
        if (nx[i + 1] >= x && x + nx[i + 1] <= i + 1)
            return true;
    return false;
}
void getnext()
{
    nx[0] = -1;
    for (int i = 0, j = -1; i < len; )
    {
        if (j == -1 || str[i] == str[j])
            nx[++i] = ++j;
        else
            j = nx[j];
    } 
}
void solve()
{
    scanf("%d", &len);
    scanf("%s", str);
    getnext();
    for (int ans = min(len / 3, nx[len - 1] + 1); ans >= 1; --ans)
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

// 不知道哪里WA了