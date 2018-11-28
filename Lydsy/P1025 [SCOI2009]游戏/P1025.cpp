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
const int N = 1e3 + 10;
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
int n,phi[N],cnt = 0;
bool mark[N];
void Getprim()
{
	int lim = 1e3;
	Clre(mark);
	for (int i = 2;i <= lim;++i)
	{
		if (!mark[i])
			phi[++cnt] = i;
		for (int j = 1;j <= cnt && i * phi[j] <= lim;++j)
		{
			mark[i * phi[j]] = true;
			if (i % phi[j] == 0)
				break;
		}
	}
}
ll f[N][N],ans = 0;
void Dp()
{
	f[0][0] = 1;
	for (int i = 1;i <= cnt;++i)
	{
		for (int j = 0;j <= n;++j)
			f[i][j] = f[i - 1][j];
		for (int j = phi[i]; j <= n;j *= phi[i])
			for (int k = 0;k + j <= n;++k)
				f[i][k + j] += f[i - 1][k];
	}
	for (int i = 0;i <= n;++i)
		ans += f[cnt][i];
}

void solve()
{
    f[0][0]=1;
    for(int i=1;i<=cnt;i++)
    {
	for(int j=0;j<=n;j++)f[i][j]=f[i-1][j];
	for(int j=phi[i];j<=n;j*=phi[i])
	    for(int k=0;k<=n-j;k++)
	f[i][k+j]+=f[i-1][k];
    }
    for(int i=0;i<=n;i++)ans+=f[cnt][i];
}
int main()
{
	n = read();
	Getprim();
	Dp();
	printf("%lld\n",ans);
    return 0;
}


