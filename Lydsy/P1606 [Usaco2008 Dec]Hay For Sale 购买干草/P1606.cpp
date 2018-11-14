#include <cstdio>
#include <algorithm>
const int N = 5000 + 10;
const int M = 50000 + 10;
using namespace std;
int m,n,w[N];

void Readin()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;++i)
        scanf("%d",w + i);
}

int f[M];
void Dp()
{
    for (int i=1;i<=n;++i)
        for (int j=m;j>=w[i];--j)
            f[j] = max(f[j],f[j - w[i]] + w[i]);
    printf("%d\n",f[m]);
}

int main()
{
    Readin();
    Dp();
    return 0;
}
