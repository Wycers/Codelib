#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int d[8][2] = {{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
using namespace std;
int x,y,ans = 0;
int Abs(int x)
{
    return x >= 0 ? x : -x;
}
void Readin()
{
    int tx,ty;
    scanf("%d%d%d%d",&tx,&ty,&x,&y);
    x = Abs(x - tx);
    y = Abs(y - ty);
}

void Pre_work()
{
	while(x + y >= 50)
	{
		if(x < y)
            swap(x,y);
		if(x-4 >= 2 * y)
            x -= 4;
		else
            x -= 4,y -= 2;
		ans += 2;
	}
}

int Dis[55][105];
queue<pair<int,int> > q;
void Bfs()
{
	memset(Dis,-1,sizeof(Dis));
	q.push(make_pair(0,50));
	Dis[0][50]=0;
	while(!q.empty())
	{
	    pair<int,int> now = q.front();q.pop();
		int nx = now.first,ny = now.second;
		for(int i=0;i<8;i++)
		{
			int dx=nx + d[i][0],dy = ny + d[i][1];
			if(dx < 0 || dy < 0 || dx > 100 || dy > 100)continue;
			if(Dis[dx][dy] != -1)
                continue;
			Dis[dx][dy] = Dis[nx][ny] + 1;
            q.push(make_pair(dx,dy));
			if(dx == x && dy == y)
                return;
		}
	}
}

int main()
{
    Readin();
    Pre_work();
	y += 50;
    Bfs();
    printf("%d\n",ans + Dis[x][y]);
    return 0;
}
