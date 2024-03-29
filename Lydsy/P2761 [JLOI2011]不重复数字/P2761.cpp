#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
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
}
//Struct

//Code
map<int, bool> mp; 
int n, a[N];
void Work()
{
	mp.clear();
	n = read(); int now, cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		now = read();
		if (mp[now])
			continue;
		mp[now] = true;
		a[++cnt] = now;
	}
	for (int i = 1; i <= cnt; ++i)
		printf("%d%c", a[i], i == cnt ? '\n' : ' ');
}
int main()
{
	for (int T = read(); T; --T)
		Work();
    return 0;
}


