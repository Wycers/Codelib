#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 505;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct block
{
	int num, data;
} a[N];
//Code
int n, top, f[N][N];
int Dp(int l, int r)
{
    if (f[l][r] != -1) return f[l][r];
    if (l == r) return (a[l].num <= 2) ? 3 - a[l].num : 1;
    int res = Inf;
    if (a[l].data == a[r].data)
        res = (a[l].num + a[r].num >= 3) ? Dp(l + 1, r - 1) : Dp(l + 1, r - 1) + 1;  
    for (int i = l; i <= r - 1; ++i)
        res = min(res, Dp(l, i) + Dp(i + 1, r));
    return f[l][r] = res;
}
int main()
{
	n = read();
	a[top = 0].data = Inf;
	for (int i = 1; i <= n; ++i)
	{
		int x = read();
		if (x != a[top].data)
		{
			a[++top].data = x;
			a[top].num = 0;
		}
		a[top].num++;
	}
	n = top;
	Clr(f, -1);
	printf("%d\n", Dp(1, n));
    return 0;
}


