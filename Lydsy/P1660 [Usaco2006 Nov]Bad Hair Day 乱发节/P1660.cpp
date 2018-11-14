#include <cstdio>
const int N = 80000 + 10;
using namespace std;
int st[N],top = 0;
int n,x;
int Read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
int main()
{
    n = Read();
    long long ans = 0;
    for (int i=1;i<=n;i++)
    {
        x = Read();
        while (top && st[top] <= x) --top;
        ans += top;
        st[++top] = x;
    }
    printf("%lld\n",ans);
    return 0;
}
