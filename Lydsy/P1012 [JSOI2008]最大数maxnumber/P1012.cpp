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
const int N = 2e5 + 10;
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
int m,d,last;
char s[2]; int ans[N],a[N],p;


int main()
{
	m = read(); d = read(); last = 0; int t = 0;
	while (m--)
	{
		scanf("%s %d",s,&p);
		if (s[0] == 'A')
		{
			a[++t] = (last + p) % d;
			for (int i=t;i;--i)
				if (ans[i] < a[t])
					ans[i] = a[t];
				else 
					break;
		}
		else 
			printf("%d\n",last = ans[t - p + 1]);
	}
    return 0;
}


