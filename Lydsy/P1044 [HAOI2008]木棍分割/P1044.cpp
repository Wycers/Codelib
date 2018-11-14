#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
const int Mo = 1e4 + 7;
int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n,m,ans1,ans2;
int a[N],sum[N];
void Init()
{
	n = read(); m = read();
	for (int i=1;i<=n;++i)
		a[i] = read();
	for (int i=1;i<=n;++i)
		sum[i] = sum[i - 1] + a[i];
}
bool Judge(int x)
{
	int cnt = 0,s = 0;
	for (int i=1;i<=n;++i)
	{
		if (a[i] > x)
			return false;
		if ((s += a[i]) > x)
		{
			if (++cnt > m)
				return false;
			s = a[i];	
		}
	}
	return true;
}
void Solve1()
{
	int l = 1,r = sum[n],mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Judge(mid))
		{
			ans1 = mid;
			r = mid - 1;	
		}	
		else 
			l = mid + 1;
	}
	printf("%d ",ans1);
}
int f[2][N];
void Solve2()
{
	int now,pre,k,delta;
	memset(f,0,sizeof(f)); f[0][0] = 1;
	for (int j=1;j<=m;++j)
	{
		now = j & 1; pre = now ^ 1;
		delta = f[pre][k = 0];
		for (int i=1;i<=n;++i)
		{
			while (k < i && sum[i] - sum[k] > ans1)
				delta = (delta - f[pre][k++] + Mo) % Mo;
			f[now][i] = delta;
			delta = (delta + f[pre][i]) % Mo;
		}
		for (int i=n-1;i;--i)
		{
			if (sum[n] - sum[i] > ans1)
				break;
			ans2 = (ans2 + f[now][i]) % Mo;	
		}
		memset(f[pre],0,sizeof(f[pre]));
	}
	printf("%d\n",ans2);
}

int main()
{
	Init();
	Solve1();
	Solve2();
    return 0;
}

