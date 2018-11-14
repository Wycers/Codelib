#include <cstdio>
using namespace std;
int a[305][305],t[105][305][305];
int n,m;
inline int read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x;
}

inline int lowbit(int x)
{
    return x&(-x);
}

inline int Query(int x,int y,int c)
{
    int temp = 0;
    for (int i=x;i;i-=lowbit(i))
        for (int j=y;j;j-=lowbit(j))
            temp += t[c][i][j];
    return temp;
}

void Update(int x,int y,int c,int val)
{
    for (int i=x;i<=n;i+=lowbit(i))
        for (int j=y;j<=m;j+=lowbit(j))
            t[c][i][j] += val;
}

void Readin()
{
    n = read(),m = read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            a[i][j] = read();
            Update(i,j,a[i][j],1);
        }
}

void Work()
{
    int Q,Opt,x1,x2,y1,y2,C;
    for (scanf("%d",&Q);Q--;)
    {
        Opt = read();
        if (Opt == 1)
        {
            x1 = read();y1 = read();
            C = read();
            Update(x1,y1,a[x1][y1],-1);
            a[x1][y1] = C;
            Update(x1,y1,a[x1][y1],1);
        }
        else
        {
            x1 = read();x2 = read();
            y1 = read();y2 = read();
            C = read();
            int ans = 0;
            ans = Query(x2,y2,C) + Query(x1 - 1,y1 - 1,C);
            ans -= Query(x1 - 1,y2,C);
            ans -= Query(x2,y1 - 1,C);
            printf("%d\n",ans);
        }
    }
}

int main()
{
    Readin();
    Work();
    return 0;
}
