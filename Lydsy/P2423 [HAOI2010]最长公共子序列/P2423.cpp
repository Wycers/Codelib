#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 5e3 + 10;
const int Mo = 1e8;
const int Inf = 0x3f3f3f3f;
 
int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
 
//Code
char str1[N], str2[N];
int f[2][N], g[2][N], len1, len2;
int main()
{
    scanf("%s", str1 + 1); len1 = strlen(str1 + 1) - 1;
    scanf("%s", str2 + 1); len2 = strlen(str2 + 1) - 1;
    for (int i = 0; i <= len2; ++i)
        g[0][i] = 1;
    g[1][0] = 1;
    int i, j, cur = 0;
    cur = 0;
    for (i = 1; i <= len1; ++i)
        for (j = 1, cur ^= 1; j <= len2; ++j)
            if (str1[i] == str2[j])
            {
                f[cur][j] = f[!cur][j - 1] + 1;
                g[cur][j] = g[!cur][j - 1];
                if (f[cur][j] == f[cur][j - 1])
                    g[cur][j] += g[cur][j - 1], g[cur][j] %= Mo;
                if (f[cur][j] == f[!cur][j])
                    g[cur][j] += g[!cur][j], g[cur][j] %= Mo;
            }
            else
            {
                f[cur][j] = f[!cur][j]; g[cur][j] = g[!cur][j];
                if (f[cur][j - 1] > f[cur][j])
                {
                    f[cur][j] = f[cur][j - 1];
                    g[cur][j] = g[cur][j - 1];
                }
                else if (f[cur][j - 1] == f[cur][j])
                {
                    g[cur][j] += g[cur][j - 1];
                    if (f[!cur][j - 1] == f[cur][j])
                        g[cur][j] -= g[!cur][j - 1];
                    g[cur][j] %= Mo;
                }
            }
    printf("%d\n%d\n", f[cur][len2], g[cur][len2]);
    return 0;
}
