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
int q[255];
char str[205], a[4][20][2], p[4] = {'W', 'I', 'N', 'G'};
int f[205][205][4], t[4];
bool Dp(int l, int r, int k)
{
	int& res = f[l][r][k];
	if (res != -1)
		return res;
	if (l == r)
		return res = (str[l] == p[k]);
	for (int i = 1; i <= t[k]; ++i)
		for (int j = l; j < r; ++j)
			if (Dp(l, j, q[a[k][i][0]]) && Dp(j + 1, r, q[a[k][i][1]]))
				return res = 1;
	return res = 0;
}
int main()
{
	q['W'] = 0; q['I'] = 1; q['N'] = 2; q['G'] = 3;
	for (int i = 0; i < 4; ++i)
		t[i] = read();
	for (int i = 0; i < 4; ++i)
		for (int j = 1; j <= t[i]; ++j)
			scanf("%s", a[i][j]); 
	scanf("%s", str + 1); Clr(f, -1); 
	int len = strlen(str + 1); bool flag = false; 
	for (int i = 0; i <= 4; ++i)
		if (Dp(1, len, i))
			flag = 1, printf("%c", p[i]);
	if (!flag)
		puts("The name is wrong!");
    return 0;
}


