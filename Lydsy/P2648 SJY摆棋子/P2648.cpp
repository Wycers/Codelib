#include <cstdio>
#include <algorithm>
using namespace std;

struct Point
{
	int d[2],mn[2],mx[2],l,r;
	int& operator[](int x){return d[x];}
	Point(int x=0,int y=0)
	{l=0,r=0;d[0]=x,d[1]=y;}
} pt[500005];
int Read()
{
	int x = 0,f = -1;char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar();}
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar();}
	return x * f;
}


int main()
{
	
