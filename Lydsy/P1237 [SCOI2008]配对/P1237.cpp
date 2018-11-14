#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const ll Inf = 0x3f3f3f3f3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
int n, a[N], b[N]; ll f[N];
ll Get(int x, int y)
{
	if (a[x] == b[y])
		return (ll)Inf;
	return (ll)abs(a[x] - b[y]);
}
int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read(), b[i] = read();
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	f[1] = Get(1, 1); f[2] = min(f[1] + Get(2, 2), Get(1, 2) + Get(2, 1));
	for (int i = 3; i <= n; ++i)
	{
		//1
		f[i] = f[i - 1] + Get(i, i);
		//2
		f[i] = min(f[i], f[i - 2] + Get(i - 1, i) + Get(i, i - 1));
		//3
		f[i] = min(f[i], f[i - 3] + Get(i - 2, i - 1) + Get(i - 1, i) + Get(i, i - 2));
		f[i] = min(f[i], f[i - 3] + Get(i - 2, i - 1) + Get(i - 1, i - 2) + Get(i, i));
		f[i] = min(f[i], f[i - 3] + Get(i - 2, i) + Get(i - 1, i - 2) + Get(i, i - 1));
		f[i] = min(f[i], f[i - 1] + Get(i - 2, i) + Get(i - 1, i - 1) + Get(i ,i - 2));
		//--
		f[i] = min(f[i], Inf);
	}
	printf("%lld", f[n] > Inf ? -1 : f[n]);
    return 0;
}


