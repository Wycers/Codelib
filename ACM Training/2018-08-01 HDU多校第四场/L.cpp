#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int n, w[N];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", w + i);
    printf("%d\n", (int)sqrt(abs(w[n] - w[1])));
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}