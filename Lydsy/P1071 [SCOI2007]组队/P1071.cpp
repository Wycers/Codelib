#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 5e3 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n, a[N];
//Struct
struct data
{
	int h, v; ll val;
} H[N], V[N], S[N], q[N];
bool cmph(data a, data b)
{
	return a.h < b.h;
}
bool cmpv(data a, data b)
{
	return a.v < b.v;
}
bool cmpV(data a, data b)
{
	return a.val < b.val;
}
//Code
int A, B, C;
int main()
{
	n = read(); A = read(); B = read(); C = read();
	for (int i = 1; i <= n; ++i)
	{
		S[i].h = read(); S[i].v = read();
		S[i].val = A * S[i].h + B * S[i].v - C;
		H[i] = V[i] = S[i];
	}
	sort(H + 1, H + n + 1, cmph);
	sort(V + 1, V + n + 1, cmpv);
	sort(S + 1, S + n + 1, cmpV);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int minh = H[i].h, cnt = 0, p = 0, top = 0;
		for (int j = 1; j <= n; ++j)
			if (V[j].h >= minh && V[j].v <= H[i].v)
				q[++top] = V[j];
		for (int j = 1; j <= top; ++j)
		{
			int minv = q[j].v;
			ll res = A * minh + B * minv;
			while (p <= n && S[p].val <= res)
			{
				if(S[p].h < minh || S[p].v < minv) 
					++cnt;
				++p;
			}
			ans = max(ans, p - cnt);
			if (res >= A * q[j].h + B * q[j].v - C)
				++cnt;
			if (p == n + 1)
				break;
		}
	}
	printf("%d\n", ans);
    return 0;
}
