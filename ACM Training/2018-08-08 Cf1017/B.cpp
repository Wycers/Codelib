#include <cstdio>
const int N = 1e5 + 10;
int n; char ch1[N], ch2[N];
int main()
{
    scanf("%d", &n);
    scanf("%s", ch1 + 1);
    scanf("%s", ch2 + 1);
    int cnt[2] = {0, 0}, gg[2] = {0, 0};
    for (int i = 1; i <= n; ++i)
        ++cnt[ch1[i] - '0'];
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ch2[i] == '1')
            continue;
        ans += 1ll * cnt[(ch1[i] - '0') ^ 1];
        ans -= 1ll * gg[(ch1[i] - '0') ^ 1];
        ++gg[ch1[i] - '0'];
    }

    printf("%I64d\n", ans);
    return 0;
}