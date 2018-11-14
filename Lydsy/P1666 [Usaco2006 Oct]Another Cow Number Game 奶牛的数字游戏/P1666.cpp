#include <cstdio>
int main()
{
    int n,ans = 0;
    scanf("%d",&n);
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
