#include <cstdio>
using namespace std;
const int N = 1e3 + 10;
long long read()
{
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

long long extend_gcd(long long a, long long b, long long &x, long long &y) {  
    if (b == 0) {  
        x = 1, y = 0;  
        return a;  
    }  
    else {  
        long long r = extend_gcd(b, a % b, y, x);  
        y -= x * (a / b);  
        return r;  
    }  
}  
long long getinv(long long a, long long n) {  
    long long x, y;  
    extend_gcd(a, n, x, y);  
    x = (x % n + n) % n;  
    return x;  
}  

int n;
long long m;
long long c[N][N], a[N][N];
void solve()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = read() % m;
    
    long long t, inv = getinv(2, m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < n; ++j)
            printf("%lld ", ((a[i][j] - a[j][i] + m) % m) * inv % m);
        printf("%lld\n", ((a[i][n] - a[n][i] + m) % m) * inv % m);
    }
}
int main()
{
    while (~scanf("%d%lld", &n, &m))
        solve();
    return 0;
}