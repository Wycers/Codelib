#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m; ll x, y;
void solve()
{
    // cin >> x >> y;
    ll t = (x + y) & 1, ans;
    if (t == 0)
    {
        if ((n & 1) == 0)
        {
            ans = 1ll * (x - 1) * n / 2 + 1ll * (y + 1) / 2;
        }
        else
        {   
            ans = 1ll * ((x - 1) / 2) * n + 1ll * ((x - 1) % 2) * (ll)(n / 2 + 1) + 1ll * (y + 1) / 2;
        }
    }
    else 
    {
        if ((n & 1) == 0)
        {
            ans = 1ll * (x - 1) * n / 2 + 1ll * (y + 1) / 2;
        }
        else 
        {
            ans = 1ll * ((x - 1) / 2) * n + 1ll * ((x - 1) % 2) * (n / 2) + 1ll * (y + 1) / 2;
        }
        ans += 1ll * ceil((double)n / 2.0 * n);
    }
    cout << ans << "\t";
}
int main()
{
    cin >> n;
    freopen("test.out", "w", stdout);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            x = i, y = j;
            solve();
        }
        puts("");
    }
    // cin >> n >> m;
    // while (m--)
    //     solve();
    return 0;
}