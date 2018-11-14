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
const int N = 1e2 + 10;
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
int n, m, K, s1[N], s2[N]; 
int main()
{
	n = read(); m = read(); K = read();
	if (m == 1)
	{
		int f[N][11]; Clre(f);
		s1[0] = 0;
		for (int i = 1; i <= n; ++i)
			s1[i] = s1[i - 1] + read();
		for (int i = 1; i <= n; ++i)
			for (int k = 1; k <= K; ++k)
			{
				f[i][k] = f[i - 1][k];
				for (int j = 0; j < i; ++j)
					f[i][k] = max(f[i][k], f[j][k - 1] + s1[i] - s1[j]);
			}
		printf("%d\n", f[n][K]);
	}
	else
	{
		int f[N][N][11]; Clre(f);
		s1[0] = s2[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			s1[i] = s1[i - 1] + read();
			s2[i] = s2[i - 1] + read();	
		}	
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= K; ++k)
				{
					f[i][j][k] = max(f[i - 1][j][k], f[i][j - 1][k]);
					for (int p = 0; p < i; ++p)
						f[i][j][k] = max(f[i][j][k], f[p][j][k - 1] + s1[i] - s1[p]);
					for (int p = 0; p < j; ++p)
						f[i][j][k] = max(f[i][j][k], f[i][p][k - 1] + s2[j] - s2[p]);
					if (i == j)
						for (int p = 0; p < i; ++p)
							f[i][j][k] = max(f[i][j][k], f[p][p][k - 1] + s1[i] - s1[p] + s2[j] - s2[p]);	
				}
		printf("%d\n", f[n][n][K]);
	}
    return 0;
}

