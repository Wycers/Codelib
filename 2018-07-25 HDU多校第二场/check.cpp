#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e3 + 10;
int a[N][N], cntx[N][N];
int main()
{
    freopen("test.in", "r", stdin);
    int n = 2000;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    
    
    int cnt = 0;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j])
                ++cnt;
    
    printf("%d\n", cnt);
    

    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
            if (a[x][y])
                for (int i = 1; i <= n; ++i)
                    if (i != x && a[i][x] == 1)
                        if (++cntx[min(i, x)][max(i, x)] > 1)
                            printf("gg");
    
    return 0;
}