#include <cstdio>
const int N=205;
struct line
{
    int x, y;
} l[N * N];
int n, x[N], y[N], cnt, ans = 1;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",x + i,y + i);

    for (int i=1;i<=n-1;i++)
        for (int j=i+1;j<=n;j++)
            l[++cnt].x = x[i] - x[j], l[cnt].y = y[i] - y[j];

    for (int i=1;i<=cnt-1;i++)
    {
        bool flag = true;
        for (int j=i+1;j<=cnt;j++)
            if(l[i].x * l[j].y == l[i].y * l[j].x)
            {
                flag = false;
                break;
            }
        if(flag) ++ans;
    }
    printf("%d",ans);
    return 0;
}
