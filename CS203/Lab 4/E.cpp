#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 3e5 + 10;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int n, m;
int a[N], cur[N], pos[N];
stack<int> s;
void solve()
{
    memset(cur, 0, sizeof cur);
    memset(pos, 0, sizeof pos);
    while (!s.empty())
        s.pop();

    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();

    cur[n] = a[pos[n] = n];
    for (int i = n - 1; i >= 1; --i)
        if (a[i] > cur[i + 1])
            cur[i] = cur[pos[i] = pos[i + 1]];
        else
            cur[i] = a[pos[i] = i];

    for (int i = 1, j = 1; i <= n; ++i)
    {
        if (s.empty() || s.top() > cur[j])
            for (int k = pos[j]; j <= k; ++j)
                s.push(a[j]);
        printf("%d ", s.top());
        s.pop();
    }
    puts("");
}
int main()
{
    int T = read();
    while (T--)
        solve();
    return 0;
}