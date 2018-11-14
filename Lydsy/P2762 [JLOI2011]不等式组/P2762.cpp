#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
typedef pair<int, int> data;
const int N = 1e5 + 10;
const int lim = 1e6;
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
data p[N]; bool tag[N];
int tr[2 * lim + 10], top = 0;
void Add(int pos, int x)
{
	for (int tmp = 2 * lim + 1; pos <= tmp; pos += pos & -pos)
		tr[pos] += x; 
}
int Query(int pos)
{
	int res = 0;
	for (; pos > 0; pos -= pos & -pos)
		res += tr[pos];
	return res;
}

data get(int a, int b, int c)
{
	if (a == 0)
	{
		if (b > c)
			return make_pair(-lim, lim);
		else
			return make_pair(1, 0);
	}
	if (a > 0)
	{
		int tmp = floor((double)(c - b) / a + 1);
		if (tmp < -lim)
			return make_pair(-lim, lim);
		if (tmp > lim)
			return make_pair(1, 0);
		return make_pair(tmp, lim);
	}
	else
	{
		int tmp = ceil((double)(c - b) / a - 1);
		if (tmp > lim)
			return make_pair(-lim, lim);
		if (tmp < -lim)
			return make_pair(1, 0);
		return make_pair(-lim, tmp);
	}
}

void Insert(data tmp)
{
	Add(tmp.first + lim + 1, 1);
	Add(tmp.second + lim + 2, -1);
}
void Del(data tmp)
{
	Add(tmp.first + lim + 1, -1);
	Add(tmp.second + lim + 2, 1);
}
int main()
{
	char ch[10]; int a, b, c;
	Clr(tag, false);
	for (int T = read(); T; T--)
	{
		scanf("%s", ch);
		switch (ch[0])
		{
			case 'A':
				a = read(); b = read(); c = read();
				Insert(p[++top] = get(a, b, c));
				break;
			case 'D':
				a = read();
				if (tag[a])
					break;
				Del(p[a]);
				tag[a] = true;
				break;
			case 'Q':
				a = read();
				printf("%d\n", Query(a + lim + 1));
				break;
		}
	} 
    return 0;
}


