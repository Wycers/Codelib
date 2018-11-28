#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
#define pa make_pair
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
int x,y,n,f[N];
vector<int> pos[N];
map<pair<int,int>,int> mp;

int main()
{
	n = read();
	for (int i=1;i<=n;++i)
	{
		x = read(); y = read();
		++x; y = n - y;
		if (x > y)
			continue;
		++mp[pa(x,y)];
		if (mp[pa(x,y)] == 1)
			pos[y].push_back(x);
	}
	Clre(f);
	for (int i=1;i<=n;++i)
	{
		f[i] = f[i - 1];
		for (int j = 0,k = pos[i].size();j<k;++j)
        	f[i] = max(f[i],f[pos[i][j] - 1] + min(mp[pa(pos[i][j],i)],i - pos[i][j] + 1));
	}
	printf("%d\n",n - f[n]);
    return 0;
}


