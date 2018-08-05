#include <cstdio>
#include <algorithm>
using namespace std;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}
int a[5];
int main()
{
    for (int i = 0; i < 5; ++i)
        a[i] = read();
    sort(a, a + 5);
    int ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 4; ++j)
            for (int k = j + 1; k < 5; ++k)
                if (a[i] + a[j] > a[k])
                    ++ans;
    printf("%d\n", ans);
    return 0;
}