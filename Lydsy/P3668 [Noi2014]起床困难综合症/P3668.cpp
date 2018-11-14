#include <cstdio>
#define N 100005
using namespace std;
int n,m;
int opt[N],t[N],f[35];

void Readin()
{
    char ch[5];
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",ch);
        scanf("%d",&t[i]);
        if (ch[0] == 'A')
            opt[i] = 1;
        else if (ch[0] == 'O')
            opt[i] = 2;
        else
            opt[i] = 3;
    }
}

int Cal(int k)
{
    for (int i=1;i<=n;i++)
        if (opt[i] == 1)
            k = k & t[i];
        else if (opt[i] == 2)
            k = k | t[i];
        else
            k = k ^ t[i];
    return k;
}

void Work()
{
    int temp = Cal(0);
    for (int i=0;i<=30;i++)
        f[i] = Cal(1 << i) & (1 << i);
    int ans = 0,tot = 0;
    for (int i=30;i>=0;i--)
    {
        if ((1 << i) & temp)
            ans += (1 << i);
        else if (tot + f[i] <= m && f[i])
                ans += f[i],tot += f[i];
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
