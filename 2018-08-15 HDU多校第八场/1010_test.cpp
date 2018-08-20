#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int n, m;
int main()
{
    freopen("test.in", "w", stdout);
    srand(time(0));
    printf("%d\n", 1);
    n = m = 10;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; ++i)
        printf("%d ", rand() % 10);
    puts("");
    for (int i = 1; i <= m; ++i)
        printf("%d %d\n", rand() % 10 + 1, rand() % 10);
    return 0;
}