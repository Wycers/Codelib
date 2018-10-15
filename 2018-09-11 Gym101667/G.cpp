#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5e4 + 10;
int x[N], y[N];
int L[N], U[N];
bool flag[N];
int n, m;
int main()
{
    freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(L, 0, sizeof L);
    memset(U, 0, sizeof U);
    int tx, ty;
    scanf("%d", &ty);
    L[0] = ty;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &tx, &ty);
        ++tx;
        L[tx] = ty;
    }
    for (int i = 1; i <= 50001; ++i)
    {
        if (L[i])
            continue;
        L[i] = L[i - 1];
    }

    scanf("%d", &ty);
    U[0] = ty;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &tx, &ty);
        ++tx;
        U[tx] = ty;
    }
    for (int i = 1; i <= 50001; ++i)
    {
        if (U[i])
            continue;
        U[i] = U[i - 1];
    }
    for (int i = 0; i <= 50001; ++i)
        flag[i] = U[i] >= L[i];
    int cnt = 0; long long ans = 0;
    int last;
    for (int i = 1; i <= 50001; ++i)
    {
        if (flag[i - 1] == false && flag[i])
        {
            int j = i;
            while (j <= 50001 && flag[j])
                ++j;
            if (j == 50002)
                break;
            if (flag[j])
                continue;
            ++cnt;
            for (int k = i; k < j; ++k)
                if (flag[k])
                    ans += U[k] - L[k];
            i = j - 1;
        }
    }
    printf("%d %lld\n", cnt, ans);
    return 0;
}