#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int f[10005][5];
int n;
int main()
{
    scanf("%d", &n);
    for (int i=1;i<=4;i++)
        f[0][i] = 1;
    for (int i = 1;i <= n;i++)
        for (int j = 2;j <= 4;j++)
        {
            int temp = sqrt(i);
            if (temp * temp == i)
                f[i][1] = 1;
            for (int k = 0;k * k <= i;k++)
                f[i][j] += f[i - k * k][j - 1];
        }
    printf("%d\n",f[n][4]);
    return 0;
}
