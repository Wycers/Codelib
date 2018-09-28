#include <cstdio>
#include <cstring>
using namespace std;
const int M = 1e4 + 10;
int n, m, tr[M];
void add(int pos)
{
    for (int i = pos; i <= 10000; i += i & -i)
        ++tr[i];
}
int query(int pos)
{
    int res = 0;
    for (int i = pos; i >= 1; i -= i & -i)
        res += tr[i];
    return res;
}
int find(int x)
{
    int l = 1, r = 10000, res = 10000;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (query(mid) < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
            res = mid;
        }
    }
    return res;
}
void solve()
{
    int n, x;
    scanf("%d", &n);
    memset(tr, 0, sizeof tr);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        add(x);
        if (i & 1)
            printf("%d ", find((i + 1) >> 1));
    }   
    puts("");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}