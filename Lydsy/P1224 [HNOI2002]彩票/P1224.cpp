#include <cstdio>
#include <algorithm>
#include <cmath>
#define Eps 1e-10
const int N = 60;
using namespace std;
int n,m,x,y;
double targ;
double s[N];
bool equ(double a,double b)
{
    return (fabs(a - b) < Eps);
}
int ans = 0;
void Dfs(int k,int cnt,double res)
{
    double Min = res + s[m] - s[m - (n - cnt)];//后面能取的最小值
    double Max = res + s[k + (n - cnt) - 1] - s[k - 1];
    if (Min - targ > Eps || targ - Max > Eps)
        return;
    if (cnt == n)
    {
        if (equ(res,targ))
            ++ans;
        return;
    }
    if (k == m + 1)
        return;
    Dfs(k + 1,cnt,res);
    Dfs(k + 1,cnt + 1,res + (double) 1 / k);
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    targ = (double) x / y;
    for (int i=1;i<=m;++i)
        s[i] = s[i - 1] + (double) 1 / i;
    Dfs(1,0,0);
    printf("%d\n",ans);
    return 0;
}
