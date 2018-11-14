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
const int N = 5e3 + 10;
const int M = 1e3;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct H
{
	int a[N]; int len;
	H()
	{
		Clre(a); len = 1;
	}
	H operator + (int p)
	{	
		H c;
		c.len = len;
		for (int i=1;i<=len;++i)
			c.a[i] = a[i];
		c.a[1] += p;
		int now = 1;
		while (a[now] >= M)
		{
			c.len = max(now + 1,c.len);
			c.a[now + 1] += c.a[now] / M;
			c.a[now] %= M;
			c.len = max(++now,c.len);
		}
		return c;
	}
	H operator * (H b)
	{
		H c;
		for (int i=1;i<=len;++i)
			for (int j=1;j<=b.len;++j)
				c.a[i + j - 1] += a[i] * b.a[j];
		c.len = len + b.len;
		for (int i=1;i<=c.len;++i)
			if (c.a[i] >= M)
			{
				if (i == c.len)
				{
					++c.len;
					c.a[i + 1] = c.a[i] / M;	
				}	
				else
					c.a[i + 1] += c.a[i] / M;
				c.a[i] %= M;
			}
		while (c.len > 1 && !c.a[c.len]) --c.len;
		return c;
	}
	void Prt()
	{
		printf("%d",a[len]);
		for (int i=len - 1;i>=1;--i)
			printf("%03d",a[i]);
		puts("");
	}
};
H operator ^ (H a,int k)
{
	H c;
	c.a[c.len = 1] = 1;
	for (int i = k;i;i >>= 1,a = a * a)
		if (i & 1)
			c = c * a;
	return c;
}
H operator - (H a,H b)
{
	for (int i=1;i<=a.len;++i)
	{
		a.a[i] -= b.a[i];
		if (a.a[i] < 0)
		{
			a.a[i] += M;
			--a.a[i + 1];
		}
	}
	while (a.len > 1 && a.a[a.len] == 0) --a.len;
	return a;
} 
//Code
H f[35];
int n,d;
int main()
{
	n = read(); d = read();
	if (!d)
	{
		puts("1");
		return 0;
	}
	H nn;
	f[0].a[f[0].len = 1] = 1;
	for (int i=1;i<=d;++i)
	{
		f[i] = f[i - 1] ^ n;
		f[i] = f[i] + 1;
	}
	nn = f[d] - f[d - 1];
	nn.Prt();
    return 0;
}


