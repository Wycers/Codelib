#include <cstdio>
using namespace std;
int n;
struct data
{
    int a[101],len;
} f[101];
     
data Mul3(data a)
{
    for (int i=1;i<=a.len;i++)
        a.a[i] *= 3;
    for (int i=1;i<=a.len;i++)
        if (a.a[i] >= 10)
        {
            a.a[i + 1] += a.a[i] / 10;
            a.a[i] %= 10;
        }
    if (a.a[a.len + 1])
        a.len++;
    return a;
}
 
data Plus2(data a)
{
    a.a[1] += 2;
    int i = 1;
    while (a.a[i] >= 10)
    {
        a.a[i] -= 10;
        a.a[++i] ++;
    }
    if (i == a.len + 1)
        a.len++;
    return a;
}
 
data Sub(data a,data b)
{
    for(int i=1;i<=a.len;i++)
    {
        a.a[i] -= b.a[i];
        if(a.a[i] < 0)
        {
            a.a[i]+=10;
            a.a[i + 1]--;
        }
    }
    while(a.a[a.len]==0)a.len--;
    return a;
}
 
void Print(data a)
{
    for (int i=a.len;i>=1;i--)
        printf("%d",a.a[i]);
    printf("\n");
}
 
void Work()
{
    f[1].len = f[2].len = 1;
    f[1].a[1] = 1;
    f[2].a[1] = 5;
    for (int i=3;i<=n;i++)
        f[i] = Sub(Plus2(Mul3(f[i - 1])),f[i - 2]);
    Print(f[n]);
}
int main()
{
    scanf("%d",&n);
    Work();
    return 0;
}
