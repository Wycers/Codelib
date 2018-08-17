#include <cstdio>
#include <cstring>
const int N = 1e6 + 10;
int len, nx[N];
char str[N];
int main()
{
    int cnt = 0;
    while (~scanf("%d", &len))
    {
        if (len == 0)
            break;
        printf("Test case #%d\n", ++cnt);
        scanf("%s", str);
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
        for (i = 2; i <= len; ++i)
            if (nx[i] > 0 && i % (i - nx[i]) == 0)
                printf("%d %d\n", i, i / (i - nx[i]));
        puts("");
    }
    return 0;
}