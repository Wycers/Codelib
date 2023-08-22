#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 4e5 + 10;
const int Ha = 1000000007;
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
int n, m, top, st[N], mn[N], mx[N];
char str[5];
void solve()
{
    scanf("%d", &n);
    top = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str);
        if (str[1] == 'u')
        {
            int x = read();
            ++top;
            st[top] = mn[top] = mx[top] = x;
            if (top > 1)
                mn[top] = min(x, mn[top - 1]),
                mx[top] = max(x, mx[top - 1]);
        }
        else
        {
            if (--top)
                printf("%d\n", mx[top] - mn[top]);
            else 
                puts("0");
        }
        
    }
}
int main()
{
    int T = read();
    while (T--)
        solve();
    return 0;
}