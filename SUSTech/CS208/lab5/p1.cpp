#include <cstdio>
#include <cmath>
using namespace std;
int ans = 0;
int gao(int &v, int &n, int k)
{
    int need = ceil((double)v / k);
    if (need > n)
    {
        v -= k * n;
        ans += n;
        n = 0;
    }
    else
    {
        v = 0;
        n -= need;
        ans += need;
    }
}
void solve()
{
    int n, x, y; ans = 0;
    scanf("%d%d%d", &n, &x, &y);
    if (x & 1)
    {
        --x;
        --n;
        ++ans;
    }

    gao(y, n, 2);
    gao(x, n, 1);
    
    if (n)
        ans += n;
    ans += ceil((double)x / 2);
    ans += ceil((double)y / 3);
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}