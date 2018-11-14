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
const int N = 15;
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
int fab[N],f[N][N];
void Pre()
{
	Clre(f);
	fab[1] = 1;
	for (int i=2;i<=10;++i)
		fab[i] = fab[i - 1] * 10;
	for (int i=0;i<=9;++i)
		f[1][i] = 1;
	for (int i=2;i<=10;++i)
		for (int j=0;j<=9;++j)
			for (int k=0;k<=9;++k)
				if (abs(j - k) >= 2)
					f[i][j] += f[i - 1][k];
}

int Cal(int x)
{
	if (!x) return 0;
	int res = 0,n;
	for (n = 10;fab[n] > x;--n);
	for (int i=1;i<n;++i)
		for (int j=1;j<=9;++j)
			res += f[i][j];
	int cur = x / fab[n], pre;
	for (int i=1;i<cur;++i) res += f[n][i];
	x %= fab[n]; pre = cur;
	for (int i = n - 1; i >= 1 ;--i)
	{
		cur = x / fab[i];
		if (i != 1)
		{
			for (int j=0;j<cur;++j)
				if (abs(j - pre) >= 2)
					res += f[i][j];
		}
		else
		{
			for (int j=0;j<=cur;++j)
				if (abs(j - pre) >= 2)
					res += f[i][j];	
		}
        if(abs(pre - cur) < 2) break;
		x %= fab[i];
		pre = cur;
	}
	return res;
}

int main()
{
	int a = read(),b = read();
	Pre();
	printf("%d\n",Cal(b) - Cal(a - 1));
    return 0;
}


