#include <cstdio>
#include <cstring>
const int N = 2e5 + 10;
const int P = 10007;
int len, nx[N];
char str[N];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s", &len, str);
        memset(nx, 0, sizeof nx);
        int i = 0, j = -1;
        nx[0] = -1;
        while (i < len)
        {
            if (j == -1 || str[i] == str[j])
                nx[++i] = ++j;
            else
                j = nx[j];
        }
        int ans = 0;
        for (int i = 0; i < len; ++i)
            ans = (ans + 1 + (nx[i] > 0)) % P;
        ans = (ans + (nx[len] > 0)) % P;
        printf("%d\n", ans);
    }
    return 0;
}