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
const int N = 1e6 + 10;
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
int n,fa[N]; bool ave[N];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void un(int x,int y)
{
	if (x < y) swap(x,y);
	ave[y] = true;
	fa[y] = x;
}
int main()
{
	n = read(); int x,y; Clre(ave);
	for (int i=1;i<=n + 1;++i) fa[i] = i;
	for (int i=1;i<=n;++i)
	{
		x = find(read()); y = find(read());
		if (x == y)
			ave[x] = true;
		else 
			un(x,y);
	}
	for (int i=1;i<=n + 1;++i)
		if (!ave[i])
		{
			printf("%d\n",i - 1);
			break;
		}
    return 0;
}


