#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
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
int n, p, f[2][5000];
int main()
{
	n = read(); p = read();
	f[1][1] = 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 1, x = i & 1; j <= n; ++j)
			f[x][j] = (f[x][j - 1] + f[x ^ 1][i - j]) % p;
	if (n == 1)
		puts("1");
	else
		cout << f[n & 1][n] * 2 % p;
    return 0;
}
