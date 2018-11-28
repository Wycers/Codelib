#include <cstdio>
#include <cstring>
const int Mod = 1000000000;
const int N = 1000000 + 10;
using namespace std;
int ans = 1,n;
int f[N];
void Dp()
{
    memset(f,0,sizeof(f));
    f[0] = 1;
    for (int i=0;(1 << i) <= n;++i)
        for (int j=(1 << i);j <= n;++j)
            f[j] = (f[j] + f[j - (1 << i)]) % Mod;
}
int main()
{
    scanf("%d",&n);
    Dp();
    printf("%d\n",f[n]);
    return 0;

}
