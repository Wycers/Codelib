#include <cstdio>
void solve()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == 1 && y == 1)
        puts("Bob");
    else
        puts("Alice");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}