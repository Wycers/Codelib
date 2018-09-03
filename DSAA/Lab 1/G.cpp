#include <cstdio>
using namespace std;
typedef long long ll;
ll n, m;
bool trys(ll a, ll b, ll c)
{
    ll x = 2 * a + 2 * c;
    ll y =     b + 2 * c;
    if ((x <= n && y <= m) || (x <= m && y <= n))
        return true;
    return false;
}
bool solve()
{
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    scanf("%lld%lld", &n, &m);
    if (trys(a, b, c))
        return true;
    if (trys(a, c, b))
        return true;
    if (trys(b, a, c))
        return true;
    if (trys(b, c, a))
        return true;
    if (trys(c, a, b))
        return true;
    if (trys(c, b, a))
        return true;
    return false;
}
int main()
{
    ll T; scanf("%d", &T);
    while (T--)
        puts(solve() ? "Yes" : "No");
    return 0;
}