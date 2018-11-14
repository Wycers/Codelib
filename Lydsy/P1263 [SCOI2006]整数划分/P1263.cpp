#include <cstdio>
#define min(a,b) a < b ? a : b
const int t[5] = {0,1000,100,10,1};
int a[1500],len = 1,n;
int Get(const int &a)
{
    for (int i=1;i<=4;i++)
        if (a >= t[i])
            return 5 - i;
    return 0;
}
void Cal(int k)
{
    for (int i=1;i<=len;i++)
        a[i] *= k;
    for (int i=1;i<=len;i++)
        if (a[i] > 10000)
        {
            a[i + 1] += a[i] / 10000;
            a[i] %= 10000;
        }
    while (a[len + 1] > 0)
    {
        len ++;
        a[len + 1] += a[len] / 10000;
        a[len] %= 10000;
    }
}
void Print()
{
    int now = Get(a[len]);
    printf("%d\n",4 * (len - 1) + now);
    int tl = min(4 * (len - 1) + now,100);
    printf("%d",a[len]);
    if (tl == now)
        return;
    for (int i=len-1;i>=1;i--)
        for (int j=1;j<=4;j++)
        {
            printf("%d",a[i] / t[j]);
            now ++;
            if (now == tl)
                return;
            a[i] %= t[j];
        }
}
void Work()
{
    a[1] = 1;
    while (n > 4)
    {
        Cal(3);
        n -= 3;
    }
    Cal(n);
    Print();
}
int main()
{
    scanf("%d",&n);
    Work();
    return 0;
}
