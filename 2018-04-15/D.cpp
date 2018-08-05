#include <cstdio>
#include <cstring>
#pragma optimize("Ofast")
#pragma optimize("see4")
using namespace std;

const int N = 1e6 + 10;
int mod;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

int f[N];
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
int pow(int a, int b)
{
    int res = 1;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            res = res * a;
    return res;
}
long long powm(int a, int b)
{
    long long res = 1;
    for (long long t = a % mod; b; b >>= 1, t = t * t % mod)
        if (b & 1)
            res = res * t % mod;
    return res;
}

int len(int x)
{
    int res = 0;
    while (x) 
    {
        ++res;
        x /= 10;
    }
    return res;
}
void solve()
{
    int l1, r1, l2, r2;
    l1 = read(); r1 = read(); 
    l2 = read(); r2 = read();
    int len1 = len(l2); int len2 = len(r2);
    mod = read();
    bool flag = true;
    for (int i = len1; i <= len2; ++i)
    {
        int t1 = max(l2, pow(10, i - 1));
        int t2 = min(r2, pow(10, i) - 1);
        
        memset(f, 0, sizeof(f));
        if (t2 - t1 + 1 >= mod)
        {
            for (int j = 0; j < mod; ++j)
                f[j] = 1;
        }
        else
        {
            for (int j = t1; j <= min(t1 + mod, t2); ++j)
                f[j % mod] = 1;
        }

        bool test = true;
        if (r1 - l1 + 1 >= mod)
        {
            for (int j = 0; j < mod; ++j)
            {
                int tag = (j * powm(10, i)) % mod;
                if (!f[tag])
                {
                    test = false;
                    break;
                }
            }
        }
        // else
        // {
        //     for (int j = l1; j <= min(r1, l1 + mod); ++j)
        //         if (!f[(j % mod) * powm(10, i) % mod])
        //         {
        //             test = false;
        //             break;
        //         }
        // }
        flag = flag && !test;
    }
    puts(flag ? "WIN" : "LOSE");
}

int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}