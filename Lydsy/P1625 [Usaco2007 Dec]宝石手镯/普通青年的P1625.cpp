#include <cstdio>
#include <algorithm>
const int N = 3500;
const int M = 13000;
using namespace std;
int v[N],w[N];
int n,m;

int Read()
{
    int x = 0;char ch = getchar();
    while (!('0' <= ch && ch <= '9')) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
void Readin()
{
    n = Read(); m = Read();
    for (int i=1;i<=n;i++)
        w[i] = Read(),v[i] = Read();
}

int f[2][M];
void Dp()
{
    int t;
    for (int i=1;i<=n;i++)
    {
        t = i % 2;
        for (int j=w[i];j<=m;j++)
        {
            f[t][j] = f[t ^ 1][j];
            if (j >= w[i])
                f[t][j] = max(f[t][j],f[t ^ 1][j - w[i]] + v[i]);
        }
    }
    printf("%d\n",f[n % 2][m]);
}

int main()
{
    Readin();
    Dp();
    return 0;
}
