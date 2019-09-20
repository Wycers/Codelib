#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 10;
int a[N], h[N], top;
void add(int x)
{
    h[++top] = x;
    int pos = top;
    if (pos == 1)
        return;
    while (pos != 1)
    {
        if ( h[pos >> 1] > h[pos])
            swap(h[pos], h[pos >> 1]);
        else
            break;
        pos >>= 1;
    }
}
void del()
{
    swap(h[1], h[top]);
    --top;
    int pos = 1;
    while ((pos << 1) <= top)
    {
        int t = pos;
        if (h[t] > h[pos << 1])
            t = pos << 1;
        if ((pos << 1 | 1) <= top && h[t] > h[pos << 1 | 1])
            t = pos << 1 | 1;
        if (t == pos)
            break;
        swap(h[t], h[pos]);
        pos = t;
    }
} 
void solve()
{
    int n, k;
    scanf("%d", &n); k = sqrt(n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int t = n;
    while (t--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        top = 0;
        for (int i = x; i <= n; i += y)
        {
            if (top == k)
            {
                if (a[i] <= h[1])
                    continue;
                else
                {
                    add(a[i]);
                    del();
                }
            }
            else
                add(a[i]);
        }
        printf("%d\n", top < k ? -1 : h[1]);
    }
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}