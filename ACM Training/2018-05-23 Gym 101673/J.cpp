#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct dataA
{
    int u, r;
} a[10];
struct dataB
{
    int u, r, t;
} b[10];
int main()
{
    for (int i = 0; i < 10; ++i)
        scanf("%d%d", &a[i].u, &a[i].r);
    for (int i = 0; i < 10; ++i)
        scanf("%d%d%d", &b[i].u, &b[i].r, &b[i].t);
    int ans = 0;
    for (int t = 0; t < 3; ++t)
        for (int j = 0; j < 10; ++j)
        {
            if (ans < b[j].t)
            {
                b[j].t = max(b[j].t, ans + a[j].u);
                ans += a[j].u + a[j].r;
            }
            else 
            {
                while (b[j].t <= ans)
                    b[j].t += b[j].u + b[j].r;
                ans = max(ans, b[j].t - b[j].r);
                ans += a[j].u;
                b[j].t = max(b[j].t, ans);
                ans += a[j].r;
            }
        }
    printf("%d\n", ans - a[9].r);
    return 0;
}