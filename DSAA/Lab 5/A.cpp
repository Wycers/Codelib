#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[110], ch[10010]; 
int n;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str);
        ch[i] = str[strlen(str) - 1];
    }
    int ans = 0, pre = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i < n && ch[pre] == ch[i + 1])
            continue;
        ans = max(ans, i - pre + 1);
        pre = i + 1;
    }
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}