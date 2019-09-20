#include <cstdio>
#include <cstring>
char str[110], lanran[10] = "lanran";
void solve()
{
    scanf("%s", str);
    int now = 0;
    for (int i = 0, len = strlen(str); i < len; ++i)
    {
        if (str[i] == lanran[now])
            ++now;
    }
    puts(now == 6 ? "YES" : "NO");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}