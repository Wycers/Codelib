#include <cstdio>
using namespace std;
int l[2], r[2], p[2], d[2], k;
void walk(int n)
{
    if (l[n] != r[n])
    {
        if (p[n] == l[n])
            d[n] = 1;
        else if (p[n] == r[n])
            d[n] = -1;
    }
    else
        d[n] = 0;
    
    p[n] = p[n] + d[n];
}
void solve()
{
    scanf("%d%d%d%d", l, r, p, d);
    if (d[0] == 0) 
        d[0] = -1;
    scanf("%d%d%d%d", l + 1, r + 1, p + 1, d + 1);
    if (d[1] == 0)
        d[1] = -1;
    scanf("%d", &k);
    
    if (l[1] > r[0] || l[0] > r[1])
    {
        puts("0");
        return;
    }

    int ans = 0;
    while (k--)
    {
        walk(0);
        walk(1);
        if (p[0] == p[1])
            ++ans;
    }
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}