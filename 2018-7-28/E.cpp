#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
const int N = 2e3 + 10;
ll mod = 1e9 + 7;
ll pow(ll a, ll b)
{
    ll res = 1;
    for ( ; b; b >>= 1, a = (a * a) % mod)
        if (b & 1)
            res = (res * a) % mod;
    return res;
}

int n;
struct point
{
    int x, y; ll p;
    bool operator < (const point &a) const
    {
        return x < a.x;
    }
} p[N];
void init()
{
    scanf("%d", &n); int a, b;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &p[i].x, &p[i].y, &a, &b);
        p[i].p = a * pow(b, mod - 2);
    }
}

int tmp[N];
void solve()
{
    for (int i = 1; i <= n; ++i)
        tmp[i] = p[i].y;
    sort(tmp + 1, tmp + n + 1);
    int cnt = 
    for (int i = 1; i <= n; ++i)
	{
		int pos = lower_bound(tmp + 1, tmp + 1 + tot, a[i]) - tmp;
	}
    
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        init();
        solve();
    }
}