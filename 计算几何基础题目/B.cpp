#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e3 + 10;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}
int n, m, x1, y1, x2, y2, s[N], t[N], tag[N];
bool cmp(int a, int b)
{
    return s[a] < s[b];
}

int cnt[N];
int cross(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - y1 * x2;
}
bool judge(int x0, int y0, int k)
{
    return cross(x0 - t[k], y0 - y2, s[k] - t[k], y1 - y2) > 0;
}
void solve() 
{
    m = read(); x1 = read(); y1 = read(); x2 = read(); y2 = read();
    for (int i = 1; i <= n; ++i)
    {
        s[i] = read(); 
        t[i] = read();
        tag[i] = i;
    }
    s[0] = t[0] = x1; tag[0] = 0;
    
    sort(tag, tag + n + 1, cmp);
    
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= m; ++i)
    {
        int l = 0, r = n, mid, res;
        int x0 = read();
        int y0 = read();
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (judge(x0, y0, tag[mid]))
            {
                l = mid + 1;
                res = tag[mid];
            }
            else
                r = mid - 1;
        }
        ++cnt[res];
    }
    sort(cnt, cnt + n + 1);
    puts("Box");
    cnt[n + 1] = -1;
    for (int i = 0, last = 0; i <= n; ++i)
        if (cnt[i] != cnt[i + 1])
        {
            if (cnt[i] != 0)
                printf("%d: %d\n", cnt[i], i - last + 1);
            last = i + 1;
        }
}
int main()
{
    while ((n = read()) != 0)
        solve();
    return 0;
}