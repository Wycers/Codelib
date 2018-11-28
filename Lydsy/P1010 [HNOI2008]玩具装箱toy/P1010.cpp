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
const int N = 5e4 + 10;
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
int n;
ll c[N],f[N],sum[N],L;
void Init()
{
	n = read(); L = read(); sum[0] = 0;
	for (int i=1;i<=n;++i)
		sum[i] = sum[i - 1] + (c[i] = read());
}
struct node
{
	int l,r,p;
} q[N];
ll sqr(ll x) { return x * x; }
ll Cal(int j,int i)
{
	return f[j] + sqr(sum[i] - sum[j] + i - j - 1 - L);
}
int find(node t,int q)
{
	int l = t.l,r = t.r,mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Cal(q,mid) < Cal(t.p,mid))
			r = mid - 1;
		else
			l = mid + 1;	
	}
	return l;
}
void Dp()
{
	int l = 1,r = 0;
	q[++r] = (node){0,n,0};
	for(int i=1;i<=n;i++)
	{
		if(q[l].r < i) ++l;
		f[i] = Cal(q[l].p,i);
		if(l > r || Cal(i,n) < Cal(q[r].p,n))
		{
			while(l <= r && Cal(i,q[r].l) < Cal(q[r].p,q[r].l))
				--r;
			if(l <= r)
			{
				int t = find(q[r],i);
				q[r].r = t - 1;
				q[++r] = (node){t,n,i};
			}
			else
				q[++r] = (node){i,n,i};
		}
	}
}
int main()
{
	Init();
	Dp();
	printf("%lld\n",f[n]);
    return 0;
}


