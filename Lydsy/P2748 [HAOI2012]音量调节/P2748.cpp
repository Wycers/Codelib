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
const int N = 60;
const int M = 1e3 + 10;
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
int n,s,m;int c[N];
void Readin()
{
	n = read(); s = read(); m = read();
	for (int i=1;i<=n;++i)
		c[i] = read();
}
bool f[N][M];
void Dp()
{
	Clre(f);
	f[1][s] = true;
	for (int i=1;i<=n;++i)
		for (int j=0;j<=m;++j)
			if (f[i][j])
			{
				if (j + c[i] <= m)
					f[i + 1][j + c[i]] = true;
				if (j - c[i] >= 0)
					f[i + 1][j - c[i]] = true;
			}
	for (int i=m;i>=0;--i)
		if (f[n + 1][i])
		{
			printf("%d\n",i);
			return;	
		}
	puts("-1");
}

int main()
{
	Readin();
	Dp();
    return 0;
}


