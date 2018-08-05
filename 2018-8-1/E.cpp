#include <cstdio>
using namespace std;
int n, a[10];
int mp[100][100], l;
long long sum[100][100];
const long long mod = 1e9 + 7;

void init()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    l = n * n;
    for (int i = 0; i < l; ++i)
    {
        int tag = i * (i + 1) / 2;
        for (int j = 0; j < l; ++j)
        {
            tag += j + i;
            mp[i][j] = tag % n;
        }
    }
    sum[0][0] = a[mp[0][0]];
    for (int i = 1; i < l; ++i)
        sum[0][i] = sum[0][i - 1] + a[mp[0][i]];
    for (int i = 1; i < l; ++i)
        sum[i][0] = sum[i - 1][0] + a[mp[i][0]];
    for (int i = 1; i < l; ++i)
        for (int j = 1; j < l; ++j)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[mp[i][j]];
}

long long count(int x, int y)
{
    if (x < 0 || y < 0)
        return 0;
    long long cntx = x / l, cnty = y / l;
    x %= l; y %= l;
    if (cntx == 0 && cnty == 0)
        return sum[x][y];
    if (cntx == 0)
        return cnty * sum[x][l - 1]  + sum[x][y];
    if (cnty == 0)
        return cntx * sum[l - 1][y]  + sum[x][y];
    return cntx * cnty * sum[l - 1][l - 1] + cnty * sum[x][l - 1] + cntx * sum[l - 1][y] + sum[x][y];     
}
void solve()
{
    int q, sx, sy, ex, ey;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey); 
        --sx; --sy;
        long long ans = count(ex, ey) + count(sx, sy) - count(sx, ey) - count(ex, sy);
        printf("%lld\n", ans);
    }  
}

signed main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        init();
        solve();
    }
    return 0;
}