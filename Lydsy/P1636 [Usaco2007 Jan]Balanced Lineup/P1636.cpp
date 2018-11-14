#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 50000 + 10;
int n,q;
int Max[N][17],Min[N][17];

int Read()
{
    int x = 0;char ch = getchar();
    while (!('0' <= ch && ch <= '9')) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
void Readin()
{
    n = Read();q = Read();
    for (int i=1;i<=n;++i)
        Max[i][0] = Min[i][0] = Read();
}

void RMQ_Init()
{
    int m = log(n) / log(2);
    for (int i=1;i<=m;++i)
        for (int j=n;j>=1;--j)
        {
            Max[j][i] = Max[j][i - 1];
            Min[j][i] = Min[j][i - 1];
            if (j + (1 << (i - 1)) <= n)
            {
                Max[j][i] = max(Max[j][i],Max[j + (1 << (i - 1))][i - 1]);
                Min[j][i] = min(Min[j][i],Min[j + (1 << (i - 1))][i - 1]);
            }
        }
}

int RMQ_Query(int l,int r)
{
    int m = log(r - l + 1) / log(2);
    int maxn = max(Max[l][m],Max[r - (1 << m) + 1][m]);
    int minn = min(Min[l][m],Min[r - (1 << m) + 1][m]);
    return maxn - minn;
}
void Solve()
{
    RMQ_Init();
    int x,y;
    while (q--)
    {
        x = Read();y = Read();
        printf("%d\n",RMQ_Query(x,y));
    }
}
int main()
{
    Readin();
    Solve();
    return 0;
}
