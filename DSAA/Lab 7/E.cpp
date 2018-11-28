#include <cstdio>
#include <algorithm>
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
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1, len = min(n, k + 1); i <= len; ++i)
        add(a[i]);
    for (int i = 2; i + k <= n; ++i)
    {
        printf("%d ", h[1]); del();
        add(a[i + k]);
    }
    while (top)
    {
        printf("%d ", h[1]);
        del();
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