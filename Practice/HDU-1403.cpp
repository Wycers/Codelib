#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
const int M = N << 1;

char str1[N], str2[N];
int n, a[M], sa[2][M], rk[2][M], v[M], h[M];

void CalSA(int k, int *sa, int *rk, int *SA, int *RK)
{
    for (int i = 1; i <= n; ++i)
        v[rk[sa[i]]] = i;
    for (int i = n; i >= 1; --i)
        if (sa[i] > k)
            SA[v[rk[sa[i] - k]]--] = sa[i] - k;
    for (int i = n - k + 1; i <= n; ++i)
        SA[v[rk[i]]--] = i;
    for (int i = 1; i <= n; ++i)
        RK[SA[i]] = RK[SA[i - 1]] + (rk[SA[i - 1]] != rk[SA[i]] || rk[SA[i - 1] + k] != rk[SA[i] + k]);
}
int GetSA()
{
    int p = 0, q = 1;
    memset(v, 0, sizeof v);
    for (int i = 1; i <= n; ++i)
        v[a[i]]++;
    for (int i = 'Z'; i <= 'z'; ++i)
        v[i] += v[i - 1];
    for (int i = 1; i <= n; ++i)
        sa[p][v[a[i]]--] = i;
    for (int i = 1; i <= n; ++i)
        rk[p][sa[p][i]] = rk[p][sa[p][i - 1]] + (a[sa[p][i]] != a[sa[p][i - 1]]);
    for (int k = 1; k < n; swap(p, q), k <<= 1)
        CalSA(k, sa[p], rk[p], sa[q], rk[q]);
    return p;
}

void GetHeight(int res)
{
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (rk[res][i] == 1)
            h[rk[res][i]] = 0;
        else
        {
            int j = sa[res][rk[res][i] - 1];
            while (a[i + k] == a[j + k])
                k++;
            h[rk[res][i]] = k;
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
        int res = GetSA();
        GetHeight(res);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (h[i] > ans && (sa[res][i - 1] < len1 && sa[res][i] > len1 || sa[res][i - 1] > len1 && sa[res][i] < len1))
                ans = h[i];
        printf("%d\n", ans);
    }
    return 0;
}