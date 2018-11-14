#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;
using namespace std;

int Read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}

int fa[2 * N],n;
void Init()
{
    for (int i=1;i<=2*n;i++)
        fa[i] = i;
}
int Find(int k)
{
    return fa[k] == k ? k : fa[k] = Find(fa[k]);
}

int a[N],b[N],c[N],cnt = 0;
int Disc[2 * N];
void Disc_Init()
{
    sort(Disc + 1,Disc + cnt + 1);
    cnt = unique(Disc + 1,Disc + cnt + 1) - Disc - 1;
}
int Disc_Find(int x)
{
    int l = 1,r = cnt,mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (Disc[mid] == x)
            return mid;
        if (x < Disc[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
}
int main()
{
    int T = Read(),u,v,t,x,y;bool flag;
    while (T--)
    {
        scanf("%d",&n);
        flag = true; cnt = 0;
        for (int i=1;i<=2*n;i++)
            fa[i] = i;
        for (int i=1;i<=n;i++)
        {
            a[i] = Disc[++cnt] = Read();
            b[i] = Disc[++cnt] = Read();
            c[i] = Read();
        }
        Disc_Init();
        for (int i=1;i<=n;i++)
            if (c[i] == 1)
            {
                u = Disc_Find(a[i]); x = Find(u);
                v = Disc_Find(b[i]); y = Find(v);
                if (x != y)
                    fa[x] = y;
            }
        for (int i=1;i<=n;i++)
            if (c[i] == 0)
            {
                u = Disc_Find(a[i]); x = Find(u);
                v = Disc_Find(b[i]); y = Find(v);
                if (x == y)
                {
                    flag = false;
                    break;
                }
            }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
