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
const int Inf = 0x3f3f3f3f;
const int Mo = 1000000007;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct 
struct data
{
	int pos, val;
} a[N];
int n, m, k;
//Code
void Readin()
{
	n = read(); m = read(); k = read();
	for (int i = 1; i <= k; ++i)
		a[i].pos = read(), a[i].val = read();
}

ll pow(ll a, ll b)
{
	ll res = 1;
	for (ll i = b; i; i >>= 1, a = a * a % Mo)
		if (i & 1)
			res = res * a % Mo;
	return res;
}

bool cmp(data a, data b)
{
	if (a.pos == b.pos)
		return a.val < b.val;
	return a.pos < b.pos;
}
void Work()
{
	sort(a + 1, a + k + 1, cmp);
	ll sum = (ll)n * (n + 1) / 2 % Mo, tmp = sum, ans = 1, tot = m;
	for (int i = 1; i <= k; ++i)
	{
		if (i != 1 && a[i].pos != a[i - 1].pos)
		{
			ans = ans * tmp % Mo;
			tmp = sum;
			tot--;	
		}
		if(a[i].pos != a[i - 1].pos || a[i].val != a[i - 1].val) 
		{
			tmp -= a[i].val;
			if (tmp < 0)
				tmp += Mo;	
		}
	}
	tot--;
	ans = ans * tmp % Mo;
	cout << ans * pow(sum, tot) % Mo << endl;
} 
int main()
{
	Readin();
	Work();
    return 0;
}

