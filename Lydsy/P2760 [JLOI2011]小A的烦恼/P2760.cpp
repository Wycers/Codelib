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
char ans[105][10005];
char s[105][105][105]; int n, h[105], w[105];
int Get(char str[])
{
	int len = strlen(str), res = 0;
	for (int i = 0; i < len; ++i)
		if (str[i] == ',')
			++res;
	return res + 1;
}
void Put(int k)
{
	while (k--) putchar(',');
}
int main()
{
	n = read(); int m = 0;
	for (int i = 1; i <= n; ++i)
	{
		m = max(m, h[i] = read());
		w[i] = 0; scanf("%s", s[i][0]);
		for (int j = 1; j <= h[i]; ++j)
		{
			scanf("%s", s[i][j]);
			w[i] = max(w[i], Get(s[i][j]));
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%s", s[i][0]);
		Put(i != n ? w[i] : w[i] - 1);
	}
	puts("");
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i > h[j])
			{
				Put(j != n ? w[j] : w[j] - 1);
				continue;
			}
			printf("%s", s[j][i]);
			Put(w[j] - Get(s[j][i]));
			if (j != n)
				Put(1);
		}
		puts("");
	}
	puts("");
    return 0;
}

