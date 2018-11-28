#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,l,ans;
int f[5][2501];
int main()
{
    scanf("%d",&n);
    l = n / 2;
    if(!(n % 2))
        --l;
    int mid;
    f[0][0]=1;
    for(k=1;k<=4;++k)
        for(i=1;i<=n;++i)
            for(j=1;j<=l;++j)
                if(i >= j)
                    f[k][i] += f[k - 1][i - j];
    printf("%d\n",f[4][n]);
    return 0;
}
