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
/*
1
2 1 
a?
?b
*/
char str[20][55];
int n, m, bin[20], b[20][26], f[20][40000];
void Add(int &x, int y)
{
	x += y;
	if (x >= 1000003)
		x -= 1000003;
}
int count(int x)
{
	int res = 0;
	for (; x; x &= x - 1)
		++res;
	return res;
}

int main()
{
	for (int i = 0; i < 20; ++i)
		bin[i] = 1 << i;
	for (int T = read(); T; T--)
	{
		Clr(f, 0); Clr(b, 0);
		n = read(); m = read();
		for (int i = 0; i < n; ++i)
			scanf("%s", str[i] + 1);
		int len = strlen(str[1] + 1);
		for (int i = 1; i <= len; ++i)
			for (int ch = 'a'; ch <= 'z'; ++ch)
				for (int j = 0; j < n; ++j)
					if (str[j][i] == '?' || str[j][i] == ch)
						b[i][ch - 'a'] |= bin[j];
					
		f[0][(1 << n) - 1] = 1;
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < bin[n]; ++j) if (f[i][j])
				for (int k = 'a'; k <= 'z'; ++k)
					Add(f[i + 1][j & b[i + 1][k - 'a']], f[i][j]);
				
		int ans = 0;	
		for (int j = 0; j < bin[n]; ++j)
			if (count(j) == m)
				Add(ans, f[len][j]);
		printf("%d\n", ans);
	} 
    return 0;
}


