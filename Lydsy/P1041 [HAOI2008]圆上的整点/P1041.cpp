#include <cstdio>
#include <cmath>
#define ll long long
ll R;
ll gcd(ll x,ll y)
{
    return y == 0 ? x : gcd(y,x % y);
}
ll Check(ll x,double y)
{
    if (y == floor(y))
    {
        long long x1 = (long long)floor(x);
        if (gcd(x1,y) == 1 && x1 != y)
            return true;
    }
    return false;
}
void Work()
{
    int sr = sqrt(2 * R),ans = 0;
    long long sa;
    double b;
    for (int d=1;d<=sr;d++)
        if ((2 * R) % d == 0)
        {
            sa = (long long)sqrt(R / d);
            for (ll a=1;a<=sa;a++)
            {
                b = sqrt((2 * R / d) - a * a);
                if (Check(a,b))
                    ans++;
            }
            if (d * d != 2 * R)
            {
                sa = (int)sqrt(d / 2);
                for (int a=1;a<=sa;a++)
                {
                    b = sqrt(d - a * a);
                    if (Check(a,b))
                        ans++;
                }
            }
        }
    printf("%d\n",4 * (ans + 1));
}
int main()
{
    scanf("%lld",&R);
    Work();
    return 0;
}
