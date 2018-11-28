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
const int N = 1e5 + 10;
const int Mo = 12345678;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
int n,m,k;
int f[305][155][25][25];
void Add(int &x,int &y)
{
	x = (x + y) % Mo;
}
void Dp()
{
	f[0][0][0][0] = 1;
	for (int i = 0;i < n + m;++i)
		for (int j=0;j <= n;++j)
			for (int x = 0;x <= k;++x)
				for (int y = 0;y <= k;++y)
					if (f[i][j][x][y])
					{
						if (x + 1 <= k && j + 1 <= n)
							Add(f[i + 1][j + 1][x + 1][max(y - 1,0)],f[i][j][x][y]);
						if (y + 1 <= k && i + 1 - j <= m)
							Add(f[i + 1][j][max(x - 1,0)][y + 1],f[i][j][x][y]);
					}
	int ans = 0;
    for(int i=0;i<=n;++i)
        for(int x=0;x<=k;++x)
            for(int y=0;y<=k;++y)
            	Add(ans,f[n + m][i][x][y]);
    printf("%d\n",ans);
}
int main()
{
	n = read(); m = read(); k = read();
	Dp();
    return 0;
}


