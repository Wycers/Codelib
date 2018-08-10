#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
const int M = N << 1;
const int sz = 130;

char str1[N], str2[N];
int n, a[M], sa[M], rk[M], c[M], h[M];

int t[2][M];
void GetSA()
{  
    int *x = t[0], *y = t[1];
    
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++i)
        ++c[x[i] = a[i]];
    for (int i = 1; i <= sz; ++i)
        c[i] += c[i - 1];
    for (int i = n; i >= 1; --i)
        sa[c[x[i]]--] = i;

    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 1;
        for (int i = n - k + 1; i <= n; ++i)
            y[p++] = i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] >= k + 1)
                y[p++] = sa[i] - k;
        memset(c, 0, sizeof c);
        for (int i = 1; i <= n; ++i)
            ++c[x[i]];
        for (int i = 1; i <= sz; ++i)
            c[i] += c[i - 1];
        for (int i = n; i >= 1; --i)
            sa[c[x[y[i]]]--] = y[i];
        swap(x, y);
        p = 2;
        x[sa[1]] = 0;
        for (int i = 2; i <= n; ++i)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p > n)
            break;
    } 
}

void GetHeight()
{
    for (int i = 1; i <= n; ++i)
        rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= n; i++)
        if (rk[i] == 1)
            h[rk[i]] = 0;
        else
        {
            int j = sa[rk[i] - 1];
            while (a[i + k] == a[j + k])
                k++;
            h[rk[i]] = k;
            if (k > 0)
                k--;
        }
}

int main()
{
    while (scanf("%s%s", str1 + 1, str2 + 1) != EOF)
    {
        int len1 = strlen(str1 + 1), len2 = strlen(str2 + 1);
        for (int i = 1; i <= len1; ++i)
            a[i] = int(str1[i]);
        a[len1 + 1] = int('Z');
        for (int i = 1; i <= len2; ++i)
            a[i + len1 + 1] = int(str2[i]);

        n = len1 + 1 + len2;
        GetSA(); 
        GetHeight();
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (h[i] > ans && (sa[i - 1] < len1 && sa[i] > len1 || sa[i - 1] > len1 && sa[i] < len1))
                ans = h[i];
        printf("%d\n", ans);
    }
    return 0;
}