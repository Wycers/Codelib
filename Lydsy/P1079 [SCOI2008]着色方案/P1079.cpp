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
const int Inf = 0x3f3f3f3f;
const int Mo = 1e9 + 7;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
int f[16][16][16][16][16][6], x[6], n;
bool mark[16][16][16][16][16][6];
ll Dp(int a, int b, int c, int d, int e, int k)
{
	if (a + b + c + d + e == 0)
		return 1;
	if (mark[a][b][c][d][e][k])
		return f[a][b][c][d][e][k];
	ll t = 0;
	if (a)
		t += (a - (k == 2)) * Dp(a - 1, b, c, d, e, 1);
	if (b)
		t += (b - (k == 3)) * Dp(a + 1, b - 1, c, d, e, 2);
	if (c)
		t += (c - (k == 4)) * Dp(a, b + 1, c - 1, d, e, 3);
	if (d)
		t += (d - (k == 5)) * Dp(a, b, c + 1, d - 1, e, 4);
	if (e)
		t += e * Dp(a, b, c, d + 1, e - 1, 5);
	mark[a][b][c][d][e][k] = true;
	return f[a][b][c][d][e][k] = t % Mo; 
}
int main()
{
	n = read(); 
	Clre(x); Clre(mark);
	for (int i = 1; i <= n; ++i)
		x[read()]++;
	cout << Dp(x[1], x[2], x[3], x[4], x[5], 0) << endl;
    return 0;
}

