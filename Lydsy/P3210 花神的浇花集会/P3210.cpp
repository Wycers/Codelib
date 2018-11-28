#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
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
int X[N],Y[N];
 
struct Point
{
    int x, y;
    void Read(int p)
	{
		x = read(); y = read();
        X[p] = x + y;
        Y[p] = x - y;
    }
} p[N];
 
int points;
 
inline long long GetAns(int x,int y)
{
    long long re = 0;
    for(int i = 1; i <= points; ++i)
        re += abs(x - X[i]) + abs(y - Y[i]);
    return re;
}
 
int main()
{
    cin >> points;
    for(int i = 1; i <= points; ++i)
        p[i].Read(i);
    sort(X + 1,X + points + 1);
    sort(Y + 1,Y + points + 1);
    int x = X[(points + 1) >> 1],y = Y[(points + 1) >> 1];
    if((x&1 && y&1) || (!(x&1) && !(y&1)))
        cout << GetAns(x,y) / 2 << endl;
    else
        cout << min(min(GetAns(x + 1,y),GetAns(x,y + 1)),min(GetAns(x - 1,y),GetAns(x,y - 1))) / 2 << endl;
    return 0;
}

