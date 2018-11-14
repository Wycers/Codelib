#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <ctime>
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
int rd(int a, int b)
{
	int range = b - a + 1;
	int val = rand() % range + a; 
	return val; 
}
char str[2][3];
char pai[8] = {'P', 'K', 'D', 'F', 'N', 'W', 'J', 'Z'};
int main()
{
	srand(time(0));
	str[0][0] = 'Z'; str[0][1] = 'P';
	str[1][0] = 'F'; str[1][1] = 'P';
	int n = rd(1, 4), m = rd(1, 2000);
	printf("%d %d\n", n + 1, m);
	printf("MP %c %c %c %c\n", pai[rd(0, 7)], pai[rd(0, 7)], pai[rd(0, 7)], pai[rd(0, 7)]);
	for (int i = 1; i <= n; ++i)
		printf("%s %c %c %c %c\n", str[rd(0, 1)], pai[rd(0, 7)], pai[rd(0, 7)], pai[rd(0, 7)], pai[rd(0, 7)]);
	for (int i = 1; i <= m; ++i)
		printf("%c ", pai[rd(0, 7)]);
    return 0;
}


