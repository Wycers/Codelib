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
const int N = 1e5 + 10;
const int Inf = 0x3f3f3f3f;

ll read()
{
    ll x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
ll d;
ll gcd(ll a,ll b)
{
	return b == 0 ? a : gcd(b,a % b);
}
bool jud(ll x,ll y)
{
	return x % d == 0 && y % d == 0;
}
int main()
{
	int T = (int)read();
	while (T--)
	{
		ll a = read(),b=read(),x=read(),y=read();
		d = gcd(2*a,2*b);
		if(jud(x,y)||jud(x+a,y+b)||jud(x+b,y+a)||jud(x+a+b,y+a+b))puts("Y");
		else puts("N");
	}
    return 0;
}


