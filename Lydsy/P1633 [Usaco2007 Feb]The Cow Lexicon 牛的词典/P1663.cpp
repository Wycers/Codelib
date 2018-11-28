#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 605
#define L 305
using namespace std;
char a[L];
char b[N][L];
int len[N];
int n,l;

void Readin()
{
    scanf("%d%d",&n,&l);
    scanf("%s",a + 1);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",b[i] + 1);
        len[i] = strlen(b[i] + 1);
    }
}

int Cal(int x,int y)
{
    int i = x,j = 1,cnt = 0;
    while (i <= l)
    {
        if (a[i] == b[y][j])
            j++;
        else
            cnt++;
        if (j == len[y] + 1)
            return cnt;
        i++;
    }
    return -1;
}

int f[L];
void Dp()
{
    f[l + 1] = 0;
    for (int i=l;i>=1;i--)
    {
        f[i] = f[i + 1] + 1;
        for (int j=1;j<=n;j++)
        {
            int t = Cal(i,j);
            if (t != -1)
                f[i] = min(f[i],f[i + len[j] + t] + t);
        }
    }
    printf("%d\n",f[1]);
}

int main()
{
    Readin();
    Dp();
    return 0;
}
