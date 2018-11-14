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
int n; ll a[N], sum = 0, s[N];
int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		sum += (a[i] = read());
	sum /= n;
	for (int i = 2; i <= n; ++i)
		s[i] = s[i - 1] + a[i - 1] - sum;
	sort(s + 1, s + n + 1);
    int tmp = s[(n + 1) / 2];
	ll ans = 0;
    for (int i = 1; i <= n; ++i)
    	ans += abs(tmp - s[i]);
    cout << ans << endl;
    return 0;
}


