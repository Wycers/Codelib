#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n, m, a[N], b[N], tag[N];

inline bool cmp(const int &i, const int &j)
{
    return b[i] < b[j];
}
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", a + i, b + i);
        tag[i] = i;
    }

    sort(tag + 1, tag + n + 1, cmp);
    long long t = 1; int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        long long now = a[tag[i]] + b[tag[i]];
        if (now * t > m)
            break;
        t *= now;
        ++ans;
    }
    printf("%d\n", ans);
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;   
}
