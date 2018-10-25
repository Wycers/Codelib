#include <cstdio>
#include <cstring>
const int N = 2e5 + 10;
int lena, lenb;
char a[N], b[N];
bool solve()
{
    scanf("%d%d%s%s", &lena, &lenb, a, b);
    if (lena - lenb > 1)
        return false;
    int p = -1;
    for (int i = 0; i < lena; ++i)
    {
        if (a[i] == '*')
        {
            p = i;
            break;
        }
        if (a[i] != b[i])
            return false;
    }
    if (p == -1)
        return lena == lenb;
    for (int i = 1; i <= lena && lena - i != p; ++i)
        if (a[lena - i] != b[lenb - i])
            return false;
    return true;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
        puts(solve() ? "YES" : "NO");
    return 0;
}