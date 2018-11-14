#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 55;
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
int n, m, a[N]; 
bool Judge(int x)
{
	int t = min(x, m);
	for (int i = 1; i <= n; ++i)
		if (a[i] < x)
		{
			t -= (x - a[i]);
			if (t < 0)
				return false;
		}	
	return true;
}
int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; ++i) 
		a[i] = read();
	int l = 1, r = Inf, mid, ans = 0;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Judge(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	printf("%d", ans);
    return 0;
}


