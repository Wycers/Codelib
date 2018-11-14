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

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code

double f[110][100000];
int K,n,pow[20],v[20],d[20];
int main()
{
	K = read(); n = read(); int t;
	pow[0] = 1;
	for (int i=1;i<=16;++i)
		pow[i] = pow[i - 1] << 1;
	for (int i=1;i<=n;++i)
	{
		v[i] = read(); t = read();
		while (t)
		{
			d[i] += pow[t];	
			t = read();
		}
	}
	for (int i=K;i>=1;--i)
		for (int j=0;j<=pow[n + 1] - 1;++j)
		{
			for (int k=1;k<=n;++k)
				if ((d[k] & j) == d[k])
					f[i][j] += max(f[i + 1][j],f[i + 1][j | pow[k]] + v[k]);
				else 
					f[i][j] += f[i + 1][j];
			f[i][j] /= n;
		}
	printf("%.6lf\n",f[1][0]);
    return 0;
}


