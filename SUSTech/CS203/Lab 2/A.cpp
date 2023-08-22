#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N];
bool solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (m == a[mid])
            return true;
        if (m > a[mid])
        {
            l = mid + 1;
        }
        else 
            r = mid - 1;
    }
    return false;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        puts(solve() ? "YES" : "NO");
    return 0;
}