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

double x,y;int n;
double Dfs(double x,double y,int k)
{
	if (x < y)
		swap(x,y);
	if (k == 1)
		return x / y;
	double res = 1e9;
	for (int i = 1,lim = k - 1;i <= lim;++i) 
	{
		res = min(res,max(Dfs(x / k * i,y,i),Dfs(x / k * (k - i),y,k - i)));
		res = min(res,max(Dfs(x,y / k * i,i),Dfs(x,y / k * (k - i),k - i)));
	}
	return res;
}
int main()
{
	cin >> x >> y >> n;
	printf("%.6lf\n",Dfs(x,y,n));
    return 0;
}


