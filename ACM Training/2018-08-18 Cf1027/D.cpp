#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], c[N], vis[N], loop[N];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        c[i] = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        int now = i; vis[now] = i;
        while (true)
        {
            now = a[now];
            if (vis[now])
            {
                if (vis[now] == i)
                    loop[now] = true;
                break;
            }
            vis[now] = i;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        if (loop[i])
        {
            int now = i, min = 0x3f3f3f3f;
            while (true)
            {
                if (c[now] < min)
                    min = c[now];
                now = a[now];
                if (now == i)
                    break;
            }
            ans += min;
        }
    cout << ans << endl;
    return 0;
}