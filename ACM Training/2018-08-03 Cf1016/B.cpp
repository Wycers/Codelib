#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, q, s[N];
char a[N], b[N]; 
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s", a + 1);
    scanf("%s", b);
    for (int i = 1; i <= n; ++i)
    {
        bool flag = true;
        for (int j = 0; j < m; ++j)
        {
            if (a[i + j] == b[j])
                continue;
            flag = false;
            break;
        }
        if (flag)
            s[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
        s[i] += s[i - 1];
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r - l + 1 < m)
        {
            puts("0");
            continue;
        }
        printf("%d\n", s[r - m + 1] - s[l - 1]);
    }
    return 0;
}