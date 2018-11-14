#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 2500 + 10;
using namespace std;
int n,s[N];
void Readin()
{
    int temp;
    scanf("%d%d",&n,&s[0]);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&temp);
        s[i] = s[i - 1] + temp;
    }
}
int f[N];//f[i] - the cost of carrying i cows;
void Dp()
{
    f[1] = s[1] + s[0];
    for (int i=2;i<=n;++i)
    {
        f[i] = 0x7fffffff;
        for (int k=0;k<i;++k)
            f[i] = min(f[i],f[k] + s[i - k] + s[0]);
    }
    printf("%d\n",f[n] - s[0]);
}

int main()
{
    Readin();
    Dp();
    return 0;
}
