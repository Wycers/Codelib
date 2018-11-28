#include <cstdio>
#include <algorithm>
const int N = 400 + 10;
const int d[4][2] = {1,0,0,1,1,1,-1,1};
using namespace std;

void Read(int &x)
{
    x = 0;int f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
        x = x * 10 + ch - 48,ch = getchar();
    x = x * f;
}

int mp[N][N],n,nn;
void Readin()
{
    Read(n);nn = n << 1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            Read(mp[i][j]);
}
int ans = -0x7fffffff;
int Get(int x,int y,int k)
{
    int now = 0;
    int i = 0,j = 0,res = -0x7fffffff;
    while (i < n && j < n)
    {
        now += mp[x + i][y + j];
        res = max(res,now);
        if (now < 0)
            now = 0;
        i += d[k][0];j += d[k][1];
    }
    return res;
}
void Work()
{
    for (int k=1;k<=n;++k)
        for (int i=n+1;i<=nn;++i)
            mp[k][i] = mp[k][i - n];
    for (int k=n+1;k<=nn;++k)
        for (int i=1;i<=n;++i)
            mp[k][i] = mp[k - n][i];
    for (int k=n+1;k<=nn;++k)
        for (int i=n+1;i<=nn;++i)
            mp[k][i] = mp[k - n][i - n];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=0;k<3;++k)
                ans = max(ans,Get(i,j,k));
    for (int i=n+1;i<=nn;++i)
        for (int j=1;j<=n;++j)
                ans = max(ans,Get(i,j,3));
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
