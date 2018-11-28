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
char s[N],n;
int c[N][N],cnt[N];
#define d(i) (s[i] - '0')
void Init()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	Clre(c); Clre(cnt);
	c[0][0] = 1;
	for (int i=0;i<n;++i)
		for (int j=0;j<=i;++j)
			c[i + 1][j] += c[i][j],c[i + 1][j + 1] += c[i][j];
	for (int i=1;i<=n;++i)
		++cnt[d(i)]; 
}
ll Calc(int x)
{
	ll res = 1;
	for (int i=0;i<=9;++i)
		res *= c[x][cnt[i]],x -= cnt[i];
	return res;	
}
void Dp()
{
	ll ans = 0;
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<d(i);++j)
			if (cnt[j])
			{
				--cnt[j];
				ans += Calc(n - i);
				++cnt[j];
			}	
		--cnt[d(i)];	
	}
	printf("%lld\n",ans);
}
int main()
{
	Init();
	Dp();
    return 0;
}


