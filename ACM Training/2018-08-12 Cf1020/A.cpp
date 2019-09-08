#include <cstdio>
#include <cmath>
using namespace std;
int n, h, a, b, k;
int main()
{   
    scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
    while (k--)
    {
        int ta, fa, tb, fb;
        scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
        int ans = 0;
        if (ta == tb)
            ans = abs(fa - fb);
        else
        {
            ans = abs(ta - tb);
            if (fa < a)
                ans += a - fa + abs(fb - a);
            else if (fa > b)
                ans += fa - b + abs(fb - b);
            else
                ans += abs(fb - fa);
        }
        printf("%d\n", ans);
    }
    return 0;
}