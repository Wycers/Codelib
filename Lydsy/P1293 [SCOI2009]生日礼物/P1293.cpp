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
const int N = 1e6 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
int head[N],a[N],v[N],next[N],cnt = 0;
//Code
int n,k;
void Init()
{
	n = read(); k = read(); int pos,t;
	for (int i = 1;i <= k;++i)
	{
		t = read();
		while (t--)
		{
			pos = read();
			v[++cnt] = pos;
			next[i] = head[i];
			head[i] = cnt;
			a[cnt] = pos;
		}
	}
	sort(a + 1,a + cnt + 1);
}
int ans = Inf;
bool Cal(int pos)
{
	int res = 0;
	for(int i=1;i<=k;i++)
	{
		while(v[head[i]] > pos)
		{
			if (!next[head[i]])
				return false;
			head[i] = next[head[i]];
		}
		if (v[head[i]] <= pos)
			res = max(res,pos - v[head[i]]);
	}
	ans = min(ans,res);
	return true;
}
void Work()
{
	for (int i = n;i >= 2;--i)
		if (a[i] != a[i + 1])
			if (!Cal(a[i]))
				break;
	printf("%d\n",ans);
}
int main()
{
	Init();
	Work();
    return 0;
}


