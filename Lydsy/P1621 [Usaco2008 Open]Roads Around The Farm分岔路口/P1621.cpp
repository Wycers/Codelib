#include <cstdio>
using namespace std;
int n,k;
int Solve(int x)
{
    if (x <= k + 1 || ((x + k) & 1)) return 1;
    return Solve((x + k) >> 1) + Solve((x - k) >> 1);
}
int main()
{
    scanf("%d%d",&n,&k);
    printf("%d\n",Solve(n));
    return 0;
}
