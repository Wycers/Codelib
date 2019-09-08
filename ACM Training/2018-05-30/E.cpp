#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
template <typename T> inline void read(T &x) {
    char c = getchar(); int f = 1;
    for (x = 0; !isdigit(c); c = getchar()) 
        if (c == '-') 
             f = -1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - '0';
    x *= f;
}

int n, x[N], y[N], tag[2 * N], cnt; double tx[N], ty[N]; 
bool cmp(const int& a, const int& b)
{
    if (y[a] == y[b])
        return x[a] < x[b]; 
    return y[a] > y[b];
}
bool cmpp(const int& a, const int& b)
{
    if (tx[a] == tx[b])
        return ty[a] < ty[b];
    return tx[a] < tx[b];
}
void solve()
{
    read(n); 
    for (int i = 1; i <= n; ++i)
        read(x[i]), read(y[i]);
    if (n < 3)
    {
        puts("0");
        return;
    }
    x[0] = 0; x[n + 1] = n + 1;
    y[0] = y[n + 1] = 0;

    for (int i = 1; i <= n; ++i)
        tag[i] = i;
    sort(tag + 1, tag + n + 1, cmp);
    int l, r; cnt = 0;
    l = r = tag[1];
    ++cnt;
    tx[cnt] = x[tag[1]];
    ty[cnt] = y[tag[1]];
    
    for (int i = 2; i <= n; ++i)
    {
        int now = tag[i];
        if (x[l] < x[now] && x[now] < x[r])
            continue;
        
        int ll = l - 1, rr = r + 1;
        while (1 <= ll && y[ll] != y[now])
            --ll;
        if (ll < 1)
            ll = l;
        while (rr <= n && y[rr] != y[tag[i]])
            ++rr;
        if (rr > n)
            rr = r;

        if (rr > r)
        {
            if (y[rr] != y[r + 1] && y[rr] != y[r])
            {
                double k = (double)(y[r] - y[rr]) / (y[rr] - y[r + 1]);
                ++cnt;
                tx[cnt] = (double)(x[r] + k * x[r + 1]) / (k + 1);
                ty[cnt] = (double)y[rr];
            }
            ++cnt;
            tx[cnt] = (double)x[rr];
            ty[cnt] = (double)y[rr];
            r = rr;
        }
        if (ll < l)
        {
            if (y[ll] != y[l - 1] && y[ll] != y[l])
            {
                double k = (double)(y[l] - y[ll]) / (y[ll] - y[l - 1]);
                ++cnt;
                tx[cnt] = (double)(x[l] + k * x[l - 1]) / (k + 1);
                ty[cnt] = (double)y[ll];
            }
            ++cnt;
            tx[cnt] = (double)x[ll];
            ty[cnt] = (double)y[ll];
            l = ll;
        }
    }

    for (int i = 1; i <= cnt; ++i)
        tag[i] = i;
    sort(tag + 1, tag + cnt + 1, cmpp);
    double ans = 0;
    for (int i = 2; i <= cnt; ++i)
        if (fabs(tx[tag[i]] - tx[tag[i] - 1]) > 1e-8)
            ans += (ty[tag[i]] + ty[tag[i - 1]]) * (tx[tag[i]] - tx[tag[i - 1]]) / 2;
    
    for (int i = 2; i <= n; ++i)
        ans -= (double)(y[i] + y[i - 1]) * (x[i] - x[i - 1]) / 2;
    printf("%lf\n", ans);
}

int main()
{
    freopen("in", "r", stdin);
    int T; 
    for (read(T); T; --T)
        solve();
    return 0;
}