#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], cnt[N];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    
    for (int l = 1; l <= n; ++l)
        for (int r = l + 1; r <= n; ++r)
        {
            memset(cnt, 0, sizeof cnt);
            for (int i = l; i <= r; ++i)
                if (++cnt[a[i]] > 1)
                {
                    puts("No");
                    return;
                }
            
        }
    puts("Yes");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}