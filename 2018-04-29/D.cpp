#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
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
int n, m, a[N];

int f[N][20];
void rmq_init()
{
    for (int i = 0; i < n; i++) {  
        f[i][0] = a[i]; 
    }  
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            if (i + 1 + (1 << j) > n)
                f[i + 1][j] = f[i][j];
        }
}
int st(int u, int v)
{ 
    int k = (int)log2((v > n ? n : v) - u + 1.0);
    return max(f[u][k], f[(v > n ? n : v) - (1 << k) + 1][k]);
}
bool check(int x)
{
    if (x == n)
        return true;
    int sum = 0;
    int l = 0;
    while (l < n)
    {
        sum += st(l, l + x - 1) + 1;
        if (sum > m)
        {
            return false;
        }
        l += x;
    }
    return true;
}
void readin()
{
    n = read();
    m = read() + 1;
    for (int i = 0; i < n; ++i)
        a[i] = read();
}
void solve()
{
    memset(f, 0, sizeof(f));  
    rmq_init();
    for (int i = 1; i <= n; ++i)
        if (check(i))
        {
            printf("%d\n", i);
            return;
        }
}
int main()
{
    readin();
    solve();
    return 0;
}