#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e3 + 10;
char ch[N][N];
bool tag[N][N];
int n, m, a, b;

void readin()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", ch[i]);
}

void solve()
{
    memset(tag, false, sizeof tag);
    a = n >> 1, b = m >> 1;
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < m; ++j)
            if (ch[i][j] != ch [n - 1 - i][j])
                tag[i][j] = true;

    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            if (tag[i][m - 1 - j] || ch[i][j] != ch[i][m - 1 - j])
                tag[i][j] = true;

    for (int i = 1; i < a; ++i)
        tag[i][0] |= tag[i - 1][0];
    for (int j = 1; j < b; ++j)
        tag[0][j] |= tag[0][j - 1]; 
    for (int i = 1; i < a; ++i)
        for (int j = 1; j < b; ++j)
            tag[i][j] |= tag[i - 1][j] | tag[i][j - 1];

    int ans = 0;
    for (int i = 1; i < a; ++i)
        for (int j = 1; j < b; ++j)
            if (tag[i - 1][b - 1] || tag[a - 1][j - 1])
                continue;
            else
                ++ans;
    printf("%d\n", ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        readin();
        solve();
    }
    return 0;
}