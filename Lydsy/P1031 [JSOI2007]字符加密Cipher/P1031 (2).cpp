#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
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
char str[N];
int n, sa[2][N], rk[2][N], v[N], a[N];
void Init()
{
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; ++i)
	{
		a[i + n] = a[i] = int(str[i]);
		str[i + n] = str[i];
	}
	n <<= 1;
}

void CalSA(int k, int *sa, int *rk, int *SA, int *RK)
{
	for (int i = 1; i <= n; ++i)
		v[rk[sa[i]]] = i;
	for (int i = n; i >= 1; --i)
		if (sa[i] > k)
			SA[v[rk[sa[i] - k]]--] = sa[i] - k;
	for (int i = n - k + 1; i <= n; ++i)
		SA[v[rk[i]]--] = i;
	for (int i = 1; i <= n; ++i)
		RK[SA[i]] = RK[SA[i - 1]] + (rk[SA[i - 1]] != rk[SA[i]] || rk[SA[i - 1] + k] != rk[SA[i] + k]);
}
int GetSA()
{
	int p = 0, q = 1;
	Clr(v, 0);
	for (int i = 1; i <= n; ++i)
		v[a[i]]++;
	for (int i = 1; i <= 256; ++i)
		v[i] += v[i - 1];
	for (int i = 1; i <= n; ++i)
		sa[p][v[a[i]]--] = i;
	for (int i = 1; i <= n; ++i)
		rk[p][sa[p][i]] = rk[p][sa[p][i - 1]] + (a[sa[p][i]] != a[sa[p][i - 1]]);
	for (int k = 1; k < n; swap(p, q), k <<= 1)
		CalSA(k, sa[p], rk[p], sa[q], rk[q]);
	return p;
}

void Work()
{
	int res = GetSA();
	for (int i = 1; i <= n; ++i)	
		if (sa[res][i] <= n / 2)
			printf("%c", str[sa[res][i] + n / 2 - 1]);	
} 

int main()
{
	Init();
	Work();
    return 0;
}


