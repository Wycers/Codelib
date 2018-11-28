#include <cstdio>
const int N = 205;
using namespace std;

struct line
{
    int x,y;
} l[N * N];
int x[N],y[N],cnt = 0,n;

void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",x + i,y + i);
        for (int j=1;j<i;j++)
        {
            ++cnt;
            l[cnt].x = x[i] - x[j];
            l[cnt].y = y[i] - y[j];
        }
    }
}

void Work()
{
    int ans = 1;
    for (int i=2;i<=cnt;i++)
        for (int j=1;j<=i;j++)
        {
            if (j == i)
                ++ans;
            else if (l[i].x * l[j].y == l[i].y * l[j].x)
                break;
        }
    printf("%d\n",ans);
}

int main()
{
    Readin();
    Work();
    return 0;
}
