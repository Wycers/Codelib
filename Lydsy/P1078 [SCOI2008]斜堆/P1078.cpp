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
int n,fa[N],c[N][2];
int ans[N],top = 0,root = 0;
void Solve()
{
	int x = root;
	while (c[x][1] != -1) x = c[x][0];
	int t = c[x][0];
	if (t != -1 && c[t][0] == -1 && c[t][1] == -1)
		x = t;
	ans[++top] = x;
	if (x == root)
		root = c[root][0];
	int f = fa[x];
	if (f != -1)
		c[f][0] = c[x][0],fa[c[f][0]] = f;
	while (f != -1)
		swap(c[f][0],c[f][1]),f = fa[f];
}
int main()
{
	n = read(); int d;
	memset(c,-1,sizeof(c));
	memset(fa,-1,sizeof(fa));
	for (int i=1;i<=n;++i)
	{
		d = read();
		c[d % 100][d >= 100] = i;
		fa[i] = d % 100;
	}
	for (int i=1;i<=n+1;++i)
		Solve();
	while (top) printf("%d ",ans[top--]);
    return 0;
}


