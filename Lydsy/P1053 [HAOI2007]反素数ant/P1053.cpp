#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
typedef long long ll;
const int N = 1e5;
const int Inf = 0x3f3f3f3f;
using namespace std;
int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
const int p[20]={1,2,3,5,7,11,13,17,19,23,29,31,37};
ll n,ans = 1,num = 1;
void Dfs(int k,ll now,int cnt,int last)
{
	if (k == 12)
	{
		if(ans < now && num < cnt){ans = now;num = cnt;}
		if(now <= ans && num <= cnt){ans = now;num = cnt;}
		return;
	}
	int t = 1;
	for (int i=0;i<=last;++i)
	{
		Dfs(k + 1,now * t,cnt + cnt * i,i);
		t *= p[k];
		if (now * t > n)
			return;	
	}
}

int main()
{
	scanf("%lld",&n);
	Dfs(1,1,1,20);
	printf("%lld",ans);
    return 0;
}


