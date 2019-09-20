#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int a[N];
int quickSort(int L, int R, int k)
{
    if (R <= L) 
        return a[L];
    int pivot = a[L], l = L + 1, r = R;
    while (l <= r)
    {
        while (l <= r && a[r] > pivot) 
            --r;
        while (l <= r && a[l] < pivot) 
            ++l;
        if (l >= r)
            break;
        swap(a[l++], a[r--]);
    }
    a[L] = a[r]; a[r] = pivot;
    if (k <= r - 1)
        return quickSort(L, r - 1, k); 
    else 
        return quickSort(l, R, k); 
}
void solve()
{
    int ans = 0, n = read(), k = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    random_shuffle(a + 1, a + n + 1);
    printf("%d\n", quickSort(1, n, k));
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}   