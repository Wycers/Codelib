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
const int N = 310;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct edge
{
	int u,v,w;
} e[100010];
//Code
int n,m;
void Readin()
{
	int u,v,w;
	n = read(); m = read();
	for (int i=1;i<=m;++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read(); 
	}
}

int fa[N];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool Judge(int k)
{
	for (int i=1;i<=n;++i) fa[i] = i;
	int x,y,cnt = 0;
	for (int i=1;i<=m;++i)
	{
		if (e[i].w > k)	return false;
		x = find(e[i].u); y = find(e[i].v);
		if (x != y)
		{
			fa[x] = y;	
			if ((++cnt) == n - 1)
				return true;
		}
	}
	return false;
} 

bool cmp(edge a,edge b)
{
	return a.w < b.w;
}
void Work()
{
	sort(e + 1,e + m + 1,cmp);
	int l = 1,r = m,mid,ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Judge(e[mid].w))
		{
			ans = e[mid].w;
			r = mid - 1;
		}	
		else
			l = mid + 1;
	}
	printf("%d %d\n",n - 1,ans);
}

int main()
{
	Readin();
	Work();
    return 0;
}


