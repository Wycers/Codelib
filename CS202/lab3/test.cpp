#include <cstdio>
#include <cstring>
int sqr(int x)
{
    return x * x;
}
int main()
{
    int a[410];
    memset(a, 0, sizeof a);
    for (int i = 1; i <= 20; ++i)
        for (int j = 1; j <= 20; ++j)
            for (int k = 1; k <= 20; ++k)
            {
                int t = i * i + j * j + k * k + i * j + i * k + j * k;
                if (t > 400)
                    continue;
                a[t] = 1;
            }
    int cnt = 0;
    for (int i = 1; i <= 400; ++i)
        if (a[i])
        {
            ++cnt;
            printf("%d\n", i);
        }
    printf("%d\n", cnt);
    return 0;
}