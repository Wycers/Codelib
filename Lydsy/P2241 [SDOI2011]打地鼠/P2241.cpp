#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e2 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n, m, mp[N][N], sum;
//Struct

//Code
void Readin()
{
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			sum += (mp[i][j] = read());
}
int ans = Inf;
void Work(int x, int y)
{
	int t[N][N];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			t[i][j] = mp[i][j];
	for (int i = 1; i <= n - x + 1; ++i)
		for (int j = 1; j <= m - y + 1; ++j)
			if(t[i][j])
	      	{
	      		int tmp = t[i][j];
	      		for (int k = 0; k < x; ++k)
	      			for (int l = 0; l < y; ++l)
	      				if ((t[i + k][j + l] -= tmp) < 0)
	      					return;
			}
	ans = sum / (x * y);
}
void Solve()
{
	for (int i = n; i > 0; --i)
		for (int j = m; j > 0; --j)
			if (sum % (i * j) == 0 && sum / (i * j) < ans)
				Work(i, j);
	printf("%d\n", ans);
}
int main()
{
	Readin();
	Solve();
    return 0;
}


