#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 105;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
char str[N]; int n;
int f[N][N]; bool mark[N][N];
int Cal(int x)
{
	int res = 0;
	while (x) ++res, x /= 10;
	return res;
}
bool Judge(int l, int r, int cl, int cr)
{
	if ((r - l + 1) % (cr - cl + 1))
		return false;
	for (int i = l; i <= r; ++i)
		if (str[i] != str[(i - l) % (cr - cl + 1) + cl])
			return false;
	return true;
}
int Dp(int l, int r)
{
	if (mark[l][r])
		return f[l][r];
	if (l == r)
	{
		mark[l][r] = true;
		return f[l][r] = 1;
	}
	int res = r - l + 1;
	for (int i = l; i < r; ++i)
	{
		res = min(res, Dp(l, i) + Dp(i + 1, r));
		if (Judge(i + 1, r, l, i))
			res = min(res, Dp(l, i) + 2 + Cal((r - i) / (i - l + 1) + 1));	
	}
	mark[l][r] = true;
	return f[l][r] = res;
}
int main()
{
	scanf("%s", str + 1);
	printf("%d\n", Dp(1, strlen(str + 1)));
    return 0;
}


