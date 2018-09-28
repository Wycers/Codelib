#include <cstdio>
#include <iostream>
using namespace std;

const int N = 5e5 + 10;
int n, k, pos[N];
struct data
{
    int pos;
    data *pre, *nxt;
} a[N];

long long l[N], r[N];
long long cal(data* p)
{
    int cntl = 0, cntr = 0;
    for(data* now = p; &a[1] <= now && cntl <= k; now = now->pre)
        l[++cntl] = now - now->pre;
    for(data* now = p; now <= &a[n] && cntr <= k; now = now->nxt)
        r[++cntr] = now->nxt - now;
    long long res = 0;
    for(int i = 1; i <= cntl; i++)
        if(1 <= k - i + 1 && k - i + 1 <= cntr)
            res += l[i] * r[k - i + 1]; 
    return res;
}
void solve()
{
    scanf("%d%d", &n, &k); 
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        pos[x] = i;
        a[i].pos = i;
        a[i].pre = &a[i - 1];
        a[i].nxt = &a[i + 1];
    }
    a[0].pre = &a[0];
    a[n + 1].nxt = &a[n + 1];
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        data *p = &a[pos[i]];
        ans += cal(p) * i;
        p->nxt->pre = p->pre;
        p->pre->nxt = p->nxt;
    }
    cout << ans << endl;
}
int main()
{
    freopen("test.in", "r", stdin);
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}