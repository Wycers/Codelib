#include <cstdio>
const int Mo = 1e5 + 3;
using namespace std;
long long Pow(long long a,long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % Mo;
        a = (a * a) % Mo;
        b >>= 1;
    }
    return ans % Mo;
}
int main()
{
    long long m,n;
    scanf("%lld%lld",&m,&n);
    long long ans = Pow(m,n) % Mo;
    ans = ((ans + Mo - (Pow(m - 1,n - 1) * m) % Mo)) % Mo;
    printf("%lld",ans);
    return 0;
}
