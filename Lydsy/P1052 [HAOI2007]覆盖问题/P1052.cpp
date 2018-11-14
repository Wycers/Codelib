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
const int N = 2e4 + 10;
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
int n,x[N],y[N];
void Readin()
{
	n = read();
	For(i,1,n)
		x[i] = read(),y[i] = read();
}
int stack[N],top = 0;bool vis[N];
bool Dfs(int k,int l)
{
    int minx = Inf,maxx = -Inf;
    int miny = Inf,maxy = -Inf;
    if(top == n)
        return true;
    if(k == 3)
        return false;
    For(i,1,n)
        if(!vis[i])
        {
            minx = min(minx,x[i]);
            maxx = max(maxx,x[i]);
            miny = min(miny,y[i]);
            maxy = max(maxy,y[i]);
        }
    int dx[] = {minx,minx,maxx - l,maxx - l};
    int dy[] = {miny,maxy - l,miny,maxy - l};
    int temp = top;
    For(j,0,3)
    {
		For(i,1,n)
            if(!vis[i])
                if(dx[j] <= x[i] && x[i] <= dx[j] + l)
                    if(dy[j] <= y[i] && y[i] <= dy[j] + l)
                        vis[i] = true,stack[++top] = i;
        bool flag = Dfs(k + 1,l);
        while(top != temp)
            vis[stack[top--]] = false;
        if(flag)
            return true;
    }
    return false;
}
//10 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10
void Work()
{
	int l = 0,r = Inf,mid,ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Dfs(0,mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else 
			l = mid + 1;
	}
	printf("%d\n",ans); 
}
int main()
{
	Readin();
	Work();
    return 0;
}


