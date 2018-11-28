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
int n, m, a[N], b[N], sa = 0, sb[N];
void Init()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	m = read();
	for (int i = 1; i <= m; ++i)
		b[i] = read();
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	
	while (b[m] > a[n]) --m;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] > b[1])
			a[++cnt] = a[i];
	n = cnt;
	for (int i = 1; i <= n; ++i)
		sa += a[i];
	sb[0] = 0;
	for (int i = 1; i <= m; ++i)
		sb[i] = sb[i - 1] + b[i];
	
	
}
int mid, bl[N]; bool flag; 
void Dfs(int ak, int bk, int w)
{
	if (!bk) flag = true;
	if (flag || ak > n) return;
	while (ak <= n && a[ak] < b[1])
		w += a[ak++];
	if (w + sb[mid] > sa) return;
	int t = ak;
	if (b[bk] == b[bk + 1] && bk != mid)
		t = bl[bk + 1];
	for (int i = t; i <= n; ++i)
		if (a[i] >= b[bk])
		{
			bl[bk] = i;
			a[i] -= b[bk];
			Dfs(ak, bk - 1, w);
			a[i] += b[bk];	
		}
}
void Work()
{
	int l = 1, r = m, ans = 0;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		flag = false;
		Dfs(1, mid, 0);
		if (flag)
		{
			ans = mid;
			l = mid + 1;	
		}
		else
			r = mid - 1;
	}	
	printf("%d\n", ans);
} 

int main()
{
	Init();
	Work();
    return 0;
}


