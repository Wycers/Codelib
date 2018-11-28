#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int N = 1e6 + 10;
const int Inf = 0x3f3f3f3f;
using namespace std;
int Read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}

int n,a[N],p[N];
long long tot = 0,ans = 0,mid;
int main()
{
	n = Read();
	for (int i=1;i<=n;++i)
	{
		a[i] = Read();
		tot += a[i];
	}
	tot /= n;
	for (int i=2;i<=n;++i)
		p[i] = p[i - 1] + tot - a[i];
	sort(p + 1,p + n + 1);
	mid = p[(n >> 1) + 1];
	for (int i=1;i<=n;++i)
		ans += (long long)abs(p[i] - mid);
	printf("%lld\n",ans);
    return 0;
}


