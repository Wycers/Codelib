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
}
//Struct

//Code
int n, m, a[N], Disc[N], cnt = 0;
void Disc_Init()
{
	sort(Disc + 1, Disc + cnt + 1);
	cnt = unique(Disc + 1, Disc + cnt + 1) - Disc - 1;
} 
int find(int x)
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
	return 0;
}

priority_queue<pair<int, int> > q;
int next[N], last[N];
void Init()
{
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = Disc[++cnt] = read();
	Disc_Init();
    memset(next,1,sizeof(next));  
	for (int i = 1; i <= n; ++i)
	{
		a[i] = find(a[i]);
		next[last[a[i]]] = i;
		last[a[i]] = i;
	}
} 
bool mark[N];
void Work()
{
	int ans = 0;
	Clr(mark, false);
	for (int i = 1; i <= n; ++i)
	{
		if (mark[a[i]])
		{
			q.push(make_pair(next[i], a[i]));
			++m;
			continue;
		}
		if (q.size() < m)
		{
			q.push(make_pair(next[i], a[i]));
			++ans;
			mark[a[i]] = true;
			continue;
		}
		pair<int, int> now = q.top(); q.pop();
		mark[now.second] = false;
		q.push(make_pair(next[i], a[i]));
		mark[a[i]] = true;
		++ans;
	}
	printf("%d\n", ans);
}
int main()
{
	Init();
	Work();
    return 0;
}


