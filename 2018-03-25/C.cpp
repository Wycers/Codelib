#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}


int n, k, a[N];
bool judge(int L)
{
    int l = 1, r = k;
    if (a[r] - a[l] > L)
        return false;
    for (int i = 1; i <= n;)
    {
        if (l <= i && i <= r)
            i = r + 1;
        else
        {
            ++l; ++r;
            while (a[r] - a[l] > L)
            {
                ++l; ++r;
                if (l > i)
                    return false;
                if (r > n)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    n = read(); k = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    sort(a + 1, a + n + 1);
    long long l = 0, r = a[n] - a[1], ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (judge(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }
    printf("%I64d\n", ans);
    return 0;
}