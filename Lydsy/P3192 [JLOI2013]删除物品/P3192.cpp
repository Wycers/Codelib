#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}//Struct
struct Type
{
	int val, pos;	
} a[N];
//Code
int Disc[N], cnt = 0;
void Disc_init()
{
	sort(Disc + 1, Disc + cnt + 1);
	cnt = unique(Disc + 1, Disc + cnt + 1) - (Disc + 1);
}
int Disc_find(int x)
{
	int l = 1, r = cnt, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Disc[mid] == x)
			return mid;
		if (Disc[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}
int n, m;
bool cmp(Type a, Type b)
{
	return a.val < b.val;
}

int t[N];
int lowbit(int x)
{
	return x & -x;
}
void Add(int pos, int val)
{
	for (int i = pos; i <= n + m; i += lowbit(i))
		t[i] += val;
}
int Query(int pos)
{
	int res = 0;
	for (int i = pos; i >= 1; i -= lowbit(i))
		res += t[i];
	return res;
}
int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = (Type){Disc[++cnt] = read(), n - i + 1};
	for (int i = 1; i <= m; ++i)
		a[i + n] = (Type){Disc[++cnt] = read(), n + i};
	/*Disc_init();
	for (int i = 1; i <= n + m; ++i)
		a[i].val = Disc_find(a[i].val);*/ 
	//其实是根本不用离散化的= =我是因为下面ll没开才wa的 
	Clr(t, 0);
	sort(a + 1, a + n + m + 1, cmp);
	for (int i = 1; i <= n + m; ++i)
		Add(i, 1);
	int mid = n; ll ans = 0;
	for (int i = n + m; i >= 1; --i)
	{
		if (a[i].pos <= mid)
		{
			ans += Query(mid) - Query(a[i].pos);
			mid = a[i].pos;
		}
        else
		{
			ans += Query(a[i].pos - 1) - Query(mid);
			mid = a[i].pos - 1;
        }
        Add(a[i].pos, -1);
	}
	printf("%lld\n", ans);
    return 0;
}

