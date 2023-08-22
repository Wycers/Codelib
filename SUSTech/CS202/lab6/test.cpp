#include <cstdio>
#include <cmath>
const float eps = 1e-5;
float FastInvSqrt(float x)
{
    float y = x;
    int i = *(int *)&x;        // evil floating point bit level hacking
    i = 0x1fbd1df5 + (i >> 1); // what the fuck?
    x = *(float *)&i;
    while (fabs(x * x - y) > eps)
        x = (x + y / x) / 2.0;
    return x;
}
int main()
{
    float x;
    while (~scanf("%f", &x))
        printf("%f\n", FastInvSqrt(x));
    return 0;
}