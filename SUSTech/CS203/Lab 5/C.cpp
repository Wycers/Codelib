#include <cstdio>
#include <cstring>

const int N = 1e6 + 10;
int n, m, nx[N];
char str[N], buf[N];

void getnext()
{
    nx[0] = -1;
    for (int i = 0, j = -1; i < m; )
    {
        if (j == -1 || str[i] == str[j])
            nx[++i] = ++j;
        else
            j = nx[j];
    }
}

void KMP()
{
    int i = 0, j = 0, ans = 0;
    while (i < n)
    {
        if (j == -1 || buf[i] == str[j])
        {
            ++i; ++j;
            if (j == m)
            {
                ++ans;
                j = nx[j];
            }
        }
        else
            j = nx[j];
    }
    printf("%d\n", ans);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        scanf("%s", buf);
        scanf("%d", &m);
        scanf("%s", str);
        getnext();
        KMP();
    }
    return 0;
}
