#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll P = 998244353;
const int N = 1e5 + 10;
int n, m, tr[N],
ll p[100005], f[100005]; 
ll pow(ll x, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1) res = res * x % P;
        x = x * x % P;
        n >>= 1;
    }
    return res;
}
void init() 
{
    p[0] = 1;
    for (int i = 1; i <= 100000; ++i)
        p[i] = p[i - 1] * i % P;

    f[0] = 1;
    for (int i = 1; i <= 100000; ++i)
        f[i] = pow(p[i], P - 2);
    return;
}
ll C(int n, int m)
{
    return (f[m] * f[n - m]) % P * p[n] % P;
}
ll comb[N];
void solve()
{
    scanf("%d%d", &n, &m);
    int opt, l, r, w, cnt = 0;
    while (m--)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d%d%d", &l, &r, &w);
        }
        else if (opt == 2)
            ++cnt;
        else if (opt == 3)
        {
            scanf("%d%d", &l, &r);
            ll ans = 0;
            for (int i = 1; i <= l - 1; ++i)
            {
                ans += cal(i, j)
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}