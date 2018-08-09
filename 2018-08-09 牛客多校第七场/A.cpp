#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
int n, ans[N];
int main()
{
    memset(ans, 0, sizeof ans);
    scanf("%d", &n);
    for (int i = n - 1; i >= 0; --i)
    {
        if (ans[i])
            continue;
        int l = 0;
        while ((1 << l) <= i)
            ++l;
        ans[i] = ((1 << l) - 1) & (~i);
        ans[((1 << l) - 1) & (~i)] = i;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    return 0;
}